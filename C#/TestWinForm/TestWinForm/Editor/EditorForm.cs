using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TestWinForm.Properties;

namespace TestWinForm
{
    public partial class EditorForm : Form
    {
        public EditorForm(string[] p_mapdata)
        {
            EditorStageData = p_mapdata;
            InitializeComponent();
            Init();

            Invalidate();
        }

        //public void SetMapData(string[] p_mapdata)
        //{
        //    EditorStageData = p_mapdata;
        //}

        string[] EditorStageData = {
                  "0000000000000000"
                , "0   0000       0"
                , "0     x x     .0"
                , "0     p        0"
                , "0           .  0"
                , "0              0"
                , "0000000000000000"
        };

        public string[] GetEditorMapData()
        {
            //CurrentStageData
            int sizey = CurrentStageData.GetLength(0);
            int sizex = CurrentStageData.GetLength(1);
            EditorStageData = new string[sizey];

            string tempstr = "";
            for (int y = 0; y < sizey; y++)
            {
                tempstr = "";
                for (int x = 0; x < sizex; x++)
                {
                    tempstr = string.Format("{0}{1}", tempstr, CurrentStageData[y, x]);
                }
                EditorStageData[y] = tempstr;
            }

            return EditorStageData;
        }

        PictureBox[,] m_CurrentPicArr = null;
        char[,] CurrentStageData = null; // 0, . // 스테이지 관련
        Size m_CurrentStageSize = new Size();

        void Init()
        {
            if (m_CurrentPicArr != null)
            {
                int sizey = m_CurrentPicArr.GetLength(0);
                int sizex = m_CurrentPicArr.GetLength(1);
                for (int y = 0; y < sizey; y++)
                {
                    for (int x = 0; x < sizex; x++)
                    {
                        m_CurrentPicArr[y, x].Dispose();
                        m_CurrentPicArr[y, x] = null;
                    }
                }

                m_CurrentPicArr = null;
            }


            m_CurrentStageSize.Height = EditorStageData.Length;
            m_CurrentStageSize.Width = EditorStageData[0].Length;

            CurrentStageData = new char[m_CurrentStageSize.Height, m_CurrentStageSize.Width];
            m_CurrentPicArr = new PictureBox[m_CurrentStageSize.Height, m_CurrentStageSize.Width];


            for (int y = 0; y < m_CurrentStageSize.Height; y++)
            {
                for (int x = 0; x < m_CurrentStageSize.Width; x++)
                {
                    CurrentStageData[y, x] = ' ';
                    if (EditorStageData[y][x] == 'p') // 플레이어
                    {
                        //m_PlayerPos.X = x;
                        //m_PlayerPos.Y = y;
                    }
                    
                    CurrentStageData[y, x] = EditorStageData[y][x];
                    
                    PictureBox picimage = CreatePictureBox();
                    picimage.Name = string.Format("{0}_{1}", x, y);

                    m_CurrentPicArr[y, x] = picimage;
                }
            }


        }

        PictureBox CreatePictureBox()
        {
            // 생성
            PictureBox picimage = new PictureBox();
            picimage.Size = Form1.GameImageSize;
            picimage.SizeMode = PictureBoxSizeMode.StretchImage;
            //this.Controls.Add(picimage);

            return picimage;
        }



        Image GetStageTypeImg(int p_x, int p_y)
        {
            if (CurrentStageData[p_y, p_x] == 'x')
                return Resources.Crate_Beige;

            if (CurrentStageData[p_y, p_x] == '.')
                return Resources.EndPoint_Beige;

            if (CurrentStageData[p_y, p_x] == 'p')
            {
                return Resources.Character4;
            }

            if (CurrentStageData[p_y, p_x] == '0')
                return Resources.Wall_Brown;

            return Resources.Ground_Grass;
        }

        void DirectRender(PaintEventArgs e)
        {

            int StageSizeY = m_CurrentStageSize.Height;
            int StageSizeX = m_CurrentStageSize.Width;

            // 벽, 골 부분 관련 작업
            for (int y = 0; y < StageSizeY; y++)
            {
                for (int x = 0; x < StageSizeX; x++)
                {
                    //PictureBox picimage = m_CurrentPicArr[y, x];// CreatePictureBox();

                    Image tempimg = GetStageTypeImg(x, y);


                    // 위치
                    Point pos = new Point(x * Form1.GameImageSize.Width
                                            , y * Form1.GameImageSize.Height);
                    e.Graphics.DrawImage(tempimg, pos.X, pos.Y
                        , Form1.GameImageSize.Width, Form1.GameImageSize.Height);
                }
            }


        }

        private void EditorForm_Paint(object sender, PaintEventArgs e)
        {
            DirectRender(e);
        }


        char m_SelectChar = ' ';
        private void WallBTN_Click(object sender, EventArgs e)
        {
            m_SelectChar = '0';
            SelectIMG.Image = WallBTN.Image;
        }

        private void GrassBTN_Click(object sender, EventArgs e)
        {
            m_SelectChar = ' ';
            SelectIMG.Image = GrassBTN.Image;
        }

        bool m_ISMouseDonw = false;
        private void EditorForm_MouseDown(object sender, MouseEventArgs e)
        {
            int indexX = e.Location.X / Form1.GameImageSize.Width;
            int indexY = e.Location.Y / Form1.GameImageSize.Height;

            Debug.WriteLine("위치값 : {0}, {1}", indexX, indexY);

            m_ISMouseDonw = true;
            CurrentStageData[indexY, indexX] = m_SelectChar;
            this.Invalidate();
        }

        private void EditorForm_MouseMove(object sender, MouseEventArgs e)
        {
            if(m_ISMouseDonw)
            {
                int indexX = e.Location.X / Form1.GameImageSize.Width;
                int indexY = e.Location.Y / Form1.GameImageSize.Height;
                if (CurrentStageData[indexY, indexX] == m_SelectChar)
                    return;

                CurrentStageData[indexY, indexX] = m_SelectChar;
                this.Invalidate();
            }

        }

        private void EditorForm_MouseUp(object sender, MouseEventArgs e)
        {
            m_ISMouseDonw = false;
        }

        private void EditorSaveBTN_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
            Close();
        }
    }
}
