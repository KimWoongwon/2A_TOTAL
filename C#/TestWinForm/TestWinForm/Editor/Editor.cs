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

namespace TestWinForm.Editor
{
    public partial class EditorForm : Form
    {
        public EditorForm( string[] p_Data)
        {
            InitializeComponent();

            StageData = p_Data;

            Init();
            Invalidate();
        }
        string[] StageData = {
                  "00000000000"
                , "0   0  x  0"
                , "0     x  .0"
                , "0     p   0"
                , "00000000000"
        };
        char[,] CurrentStageData = null; // 0, .
        char[,] CurrentBoxStageData = null; // x, p
        PictureBox[,] m_CurrentPicArr = null;

        Size m_CurrentStageSize;

        public string[] GetEditorMapData()
        {
            int sizey = CurrentStageData.GetLength(0);
            int sizex = CurrentStageData.GetLength(1);
            StageData = new string[CurrentStageData.GetLength(0)];

            string tempstr;
            for (int y = 0; y < sizey; y++)
            {
                tempstr = "";
                for (int x = 0; x < sizex; x++)
                {
                    tempstr = string.Format("{0}{1}", tempstr, CurrentStageData[y,x]);
                }
                StageData[y] = tempstr;
            }

            return StageData;
        }
        void Init()
        {
            if (m_CurrentPicArr != null)
            {
                int sizey = StageData.Length;
                int sizex = StageData[0].Length;
                for (int y = 0; y < sizey; y++)
                {
                    for (int x = 0; x < sizex; x++)
                    {
                        m_CurrentPicArr[y, x].Dispose();
                        m_CurrentPicArr[y, x] = null;
                    }
                }
            }
            m_CurrentStageSize.Height = StageData.Length;
            m_CurrentStageSize.Width = StageData[0].Length;

            CurrentStageData = new char[m_CurrentStageSize.Height, m_CurrentStageSize.Width];
            CurrentBoxStageData = new char[m_CurrentStageSize.Height, m_CurrentStageSize.Width];
            m_CurrentPicArr = new PictureBox[m_CurrentStageSize.Height, m_CurrentStageSize.Width];


            for (int y = 0; y < m_CurrentStageSize.Height; y++)
            {
                for (int x = 0; x < m_CurrentStageSize.Width; x++)
                {
                    CurrentBoxStageData[y, x] = ' ';
                    CurrentStageData[y, x] = ' ';
                    if (StageData[y][x] == 'p')
                    {
                        CurrentBoxStageData[y, x] = StageData[y][x];
                        //m_PlayerPos.X = x;
                        //m_PlayerPos.Y = y;
                    }
                    else if (StageData[y][x] == 'x')
                    {
                        CurrentBoxStageData[y, x] = StageData[y][x];
                    }
                    else
                    {
                        CurrentStageData[y, x] = StageData[y][x];
                    }

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
            if (CurrentBoxStageData[p_y, p_x] == 'x')
                return Resources.Crate_Beige;

            if (CurrentStageData[p_y, p_x] == '.')
                return Resources.EndPoint_Beige;

            if (CurrentBoxStageData[p_y, p_x] == 'p')
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

        char SelectChar = ' ';
        private void button1_Click(object sender, EventArgs e)
        {
            SelectChar = ' ';
            SelectImg.Image = button1.Image;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SelectChar = '0';
            SelectImg.Image = button2.Image;
        }

        private void EditorForm_Paint(object sender, PaintEventArgs e)
        {
            DirectRender(e);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            
            Close();
        }

        private void EditorForm_MouseDown(object sender, MouseEventArgs e)
        {
            int indexX = e.Location.X / Form1.GameImageSize.Width;
            int indexY = e.Location.Y / Form1.GameImageSize.Height;

            CurrentStageData[indexY,indexX] = SelectChar;

            this.Invalidate();
        }
    }
}
