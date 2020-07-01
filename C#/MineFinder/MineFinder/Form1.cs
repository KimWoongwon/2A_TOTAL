using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Diagnostics.Eventing.Reader;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MineFinder
{
    public partial class Form1 : Form
    {
        int MapSizeX = 3;
        int MapSizeY = 3;
        int TotalMineCount = 5;
        int[,] m_MineMap = new int[,]
        {
            {0,0,0,0,0,0,1,0,0},
            {0,1,1,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,1},
            {0,1,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,0},
        };
        PictureBox[,] PictureBoxeArray = null;
        bool[,] isOpenMap = null;
        int[,] FlagArray = null;

        List<Image> CountImageList = new List<Image> { };
        PictureBox m_tempbox = null;
        PictureBox[,] m_MineImage = null;

        DateTime StartTime;
        public Form1()
        {
            InitializeComponent();

            CountImageList.Add(global::MineFinder.Properties.Resources._0);
            CountImageList.Add(global::MineFinder.Properties.Resources._1);
            CountImageList.Add(global::MineFinder.Properties.Resources._2);
            CountImageList.Add(global::MineFinder.Properties.Resources._3);
            CountImageList.Add(global::MineFinder.Properties.Resources._4);
            CountImageList.Add(global::MineFinder.Properties.Resources._5);
            CountImageList.Add(global::MineFinder.Properties.Resources._6);
            CountImageList.Add(global::MineFinder.Properties.Resources._7);
            CountImageList.Add(global::MineFinder.Properties.Resources._8);

            StartTime = DateTime.Now;

            GameRun();
        }
        void GameRun()
        {
            List<int> m_Minedata = new List<int>();
            for (int t = 0; t < MapSizeY * MapSizeX; t++)
            {
                m_Minedata.Add(t);
            }

            m_MineMap = new int[MapSizeY, MapSizeX];
            Random rand = new Random();
            int checkcount = 0;
            for (int i = 0; i < TotalMineCount; i++)
            {
                ++checkcount;
                int pos = rand.Next(m_Minedata.Count);
                int gridpos = m_Minedata[pos];
                m_Minedata.RemoveAt(pos);

                int x = gridpos % MapSizeX;
                int y = gridpos / MapSizeX;

                m_MineMap[y, x] = 1;
            }
            Debug.WriteLine("Loop : " + checkcount.ToString());


            if (PictureBoxeArray != null)
            {
                foreach (Control item in Controls)
                {
                    this.Controls.Remove(item);
                }
            }

            PictureBoxeArray = null;
            PictureBoxeArray = new PictureBox[MapSizeY, MapSizeX];
            isOpenMap = new bool[MapSizeY, MapSizeX];
            FlagArray = new int[MapSizeY, MapSizeX];

            m_MineImage = new PictureBox[5, 5];
            for (int y = 0; y < MapSizeY; y++)
            {
                for (int x = 0; x < MapSizeX; x++)
                {
                    m_tempbox = new PictureBox();
                    if (m_MineMap[y, x] == 1)
                        m_tempbox.Image = global::MineFinder.Properties.Resources.bomb;
                    else
                        m_tempbox.Image = global::MineFinder.Properties.Resources.facingDown;
                    m_tempbox.Location = new System.Drawing.Point(x * 30 + 20, y * 30 + 20);
                    m_tempbox.Name = string.Format($"{x},{y}");
                    m_tempbox.Size = new System.Drawing.Size(30, 30);
                    m_tempbox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
                    m_tempbox.MouseClick += new System.Windows.Forms.MouseEventHandler(m_tempbox_MouseClick);
                    PictureBoxeArray[y, x] = m_tempbox;
                    isOpenMap[y, x] = false;
                    FlagArray[y, x] = 0;
                    this.Controls.Add(m_tempbox);
                }
            }

        }
        bool isOverSize(int p_gridx, int p_gridy)
        {
            int mapsize_x = m_MineMap.GetLength(1);
            int mapsize_y = m_MineMap.GetLength(0);

            if (p_gridx < 0 || p_gridx >= mapsize_x)
                return true;
            if (p_gridy < 0 || p_gridy >= mapsize_y)
                return true;
            return false;
        }
        bool isMine(int p_gridx, int p_gridy)
        {
            if (isOverSize(p_gridx, p_gridy))
                return false;
            return m_MineMap[p_gridy, p_gridx] == 1 ? true : false;
        }
        int GetArroundMine(int p_gridx, int p_gridy)
        {
            int minecount = 0;

            int x = p_gridx;
            int y = p_gridy;
            //상단 3개 검사
            if (isMine(x, y - 1)) minecount++;
            if (isMine(x - 1, y - 1)) minecount++;
            if (isMine(x + 1, y - 1)) minecount++;

            //중단 2개 검사
            if (isMine(x + 1, y)) minecount++;
            if (isMine(x - 1, y)) minecount++;

            //하단 3개 검사
            if (isMine(x - 1, y + 1)) minecount++;
            if (isMine(x, y + 1)) minecount++;
            if (isMine(x + 1, y + 1)) minecount++;

            return minecount;
        }
        PictureBox GetGridBox(int p_gridx, int p_gridy)
        {
            if (isOverSize(p_gridx, p_gridy))
                return null;
            return PictureBoxeArray[p_gridy, p_gridx];
        }

        void OpenBlock(int p_gridx, int p_gridy)
        {
            if (isOverSize(p_gridx, p_gridy))
                return;
            if (isOpenMap[p_gridy, p_gridx])
                return;

            PictureBox box = GetGridBox(p_gridx, p_gridy);
            if (m_MineMap[p_gridy, p_gridx] == 1)
            {
                box.Image = global::MineFinder.Properties.Resources.bomb;
                MessageBox.Show("Boom!");
                GameRun();
                //오픈되지 않은 지뢰들 오픈시키기.
                return;
            }


            int minecount = GetArroundMine(p_gridx, p_gridy);
            box.Image = CountImageList[minecount];
            isOpenMap[p_gridy, p_gridx] = true;
            if(minecount == 0)
            {
                //상
                OpenBlock(p_gridx, p_gridy - 1);

                //하
                OpenBlock(p_gridx, p_gridy + 1);

                //좌
                OpenBlock(p_gridx - 1, p_gridy);

                //우
                OpenBlock(p_gridx + 1, p_gridy);
            }
        }

        void SetFlag(int p_gridx, int p_gridy)
        {
            if (isOverSize(p_gridx, p_gridy))
                return;
            if (isOpenMap[p_gridy, p_gridx])
                return;
            
            FlagArray[p_gridy, p_gridx] = (FlagArray[p_gridy, p_gridx] + 1) % 3;
            PictureBox box = GetGridBox(p_gridx, p_gridy);

            switch(FlagArray[p_gridy, p_gridx])
            {
                case 1:
                    box.Image = global::MineFinder.Properties.Resources.flagged;
                    break;
                case 2:
                    box.Image = global::MineFinder.Properties.Resources.bombquestion;
                    break;
                case 0:
                    box.Image = global::MineFinder.Properties.Resources.facingDown;
                    break;
            }

        }
        bool isStageClear()
        {
            for(int y = 0; y < MapSizeY; y++)
            {
                for(int x = 0; x < MapSizeX; x++)
                {
                    if(m_MineMap[y,x] == 1)
                    {
                        if (FlagArray[y, x] != 1)
                            return false;
                    }
                }
            }
            return true;    
        }
        private void m_tempbox_MouseClick(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                PictureBox box = (PictureBox)sender;
                int x = box.Location.X / 30;
                int y = box.Location.Y / 30;

                OpenBlock(x,y);
            }

            if(e.Button == MouseButtons.Right)
            {
                PictureBox box = (PictureBox)sender;
                int x = box.Location.X / 30;
                int y = box.Location.Y / 30;

                SetFlag(x, y);
                if(isStageClear())
                {
                    TimeSpan ClearTime = DateTime.Now - StartTime;
                    MessageBox.Show("스테이지 클리어\n\t" + ClearTime.ToString(@"mm\:ss"));
                    // 재시작할수 있게끔
                    GameRun();
                }
            }
            
        }

        //Only Test Image
        bool m_isClicked = false;
        private void pictureBox1_MouseClick(object sender, MouseEventArgs e)
        {
            if (!m_isClicked)
            {
                pictureBox1.Image = global::MineFinder.Properties.Resources._0;
            }
            else
            {
                pictureBox1.Image = global::MineFinder.Properties.Resources.facingDown;
            }
            m_isClicked = !m_isClicked;
        }
    }
}
