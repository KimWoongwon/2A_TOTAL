using Sokoban.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sokoban
{
    public partial class Form1 : Form
    {
        // 이미지는 이미지대로 처리
        // render에서 처리
        // Update
        // 게임의 로직에 관한부분 처리
        // 충돌, 이동등의 처리

        // 0 = Wall, x = Box, p = Player, . = Goal
        string[] StageData =
        {
            "0000000000",
            "0  0     0",
            "0       .0",
            "0        0",
            "0        0",
            "0        0",
            "0    x   0",
            "0    p   0",
            "0000000000"
        };
        // 접근성 때문에 이런 맵으로 사용할 배열은 char나 int형으로 하는것이 좋다.
        // string에서 한개의 문자만 바꾸는게 안된다.
        char[,] CurrentStageData = null;
        Size m_CurrentStageSize = new Size();

        PictureBox[,] m_CurrentPicArr = null;

        Point PlayerPos = new Point();
        public readonly Size GameImageSize = new Size(30, 30);
        //public readonly int SizeY = 30;



        public Form1()
        {
            InitializeComponent();

            Init();
            Render();
        }

        void Init()
        {
            m_CurrentStageSize.Height = StageData.Length;
            m_CurrentStageSize.Width = StageData[0].Length;
            CurrentStageData = new char[m_CurrentStageSize.Height, m_CurrentStageSize.Width];

            m_CurrentPicArr = new PictureBox[m_CurrentStageSize.Height, m_CurrentStageSize.Width];

            PlayerPos.X = -1;
            PlayerPos.Y = -1;

            for (int y = 0; y < m_CurrentStageSize.Height; y++)
            {
                for (int x = 0; x < m_CurrentStageSize.Width; x++)
                {
                    CurrentStageData[y, x] = StageData[y][x];

                    if (CurrentStageData[y, x] == 'p')
                    {
                        PlayerPos.X = x;
                        PlayerPos.Y = y;
                    }

                    PictureBox picimage = CreatePictureBox();
                    picimage.Name = string.Format("{0}_{1}", x, y);

                    m_CurrentPicArr[y, x] = picimage;
                }
            }

            if (PlayerPos.X == -1)
            {
                // 예외처리
            }
        }

        PictureBox CreatePictureBox() // 생성
        {
            PictureBox picimage = new PictureBox();
            picimage.Size = GameImageSize;
            picimage.SizeMode = PictureBoxSizeMode.StretchImage;
            this.Controls.Add(picimage);

            return picimage;
        }

        Image GetStageTypeImg(int p_x, int p_y) // 이미지 변환용
        {
            // 예외처리가 용이하다.
            //if (p_x)
            //    return null;

            if (CurrentStageData[p_y, p_x] == 'x')
                return Resources.Crate_Beige;
            if (CurrentStageData[p_y, p_x] == 'p')
                return Resources.Character5;
            if (CurrentStageData[p_y, p_x] == '.')
                return Resources.EndPoint_Beige;
            if (CurrentStageData[p_y, p_x] == '0')
                return Resources.Wall_Brown;

            return null;
        }

        private void Render()
        {
            int StageSizeX = StageData[0].Length;
            int StageSizeY = StageData.Length;
            /*// 2차원 배열로 했을경우 조금더 나은 방법
            int StageSizeX = StageData.GetLength(1);
            int StageSizeY = StageData.GetLength(0);*/
            for (int y = 0; y < StageSizeY; y++)
            {
                for (int x = 0; x < StageSizeX; x++)
                {
                    PictureBox picimage = m_CurrentPicArr[y, x]; //CreatePictureBox();
                    picimage.Image = GetStageTypeImg(x, y);

                    //// string 배열에서 특정값을 찾고 싶은경우
                    //char chr = StageData[2][4]; // Stage에서 x를 찾고싶을때

                    // 위치
                    picimage.Location = new Point(x * GameImageSize.Width, y * GameImageSize.Height);





                }
            }


        }
        bool IsOverStage(int p_x, int p_y)
        {
            if (p_x < 0 || m_CurrentStageSize.Width <= p_x)
                return true;
            if (p_y < 0 || m_CurrentStageSize.Height <= p_y)
                return true;

            return false;
        }
        bool IsBoxMove(int p_x, int p_y)
        {
            if (IsOverStage(p_x, p_y))
                return false;
            if (CurrentStageData[p_y, p_x] == '0')
                return false;
            if (CurrentStageData[p_y, p_x] == 'x')
                return false;

            return true;
        }
        bool IsMove(int p_x, int p_y)
        {
            if (IsOverStage(p_x, p_y))
                return false;
            if (CurrentStageData[p_y, p_x] == '0')
                return false;

            return true;
        }
        private void UPBTN_Click(object sender, EventArgs e)
        {
            if(IsMove(PlayerPos.X, PlayerPos.Y - 1))
            {
                int posx = PlayerPos.X;
                int posy = PlayerPos.Y;

                if (CurrentStageData[posy - 1, posx] == 'x')
                {
                    if (IsBoxMove(PlayerPos.X, PlayerPos.Y - 2))
                    {
                        CurrentStageData[posy - 1, posx] = ' ';
                        CurrentStageData[posy - 2, posx] = 'x';

                        CurrentStageData[posy, posx] = ' ';
                        CurrentStageData[posy - 1, posx] = 'p';
                        PlayerPos.Y -= 1;
                    }
                    
                }
                else
                {
                    CurrentStageData[posy, posx] = ' ';
                    CurrentStageData[posy - 1, posx] = 'p';
                    PlayerPos.Y -= 1;
                }
                

                Render();
            }
            
        }

        private void DOWNBTN_Click(object sender, EventArgs e)
        {
            if (IsMove(PlayerPos.X, PlayerPos.Y + 1))
            {
                int posx = PlayerPos.X;
                int posy = PlayerPos.Y;

                CurrentStageData[posy, posx] = ' ';
                CurrentStageData[posy + 1, posx] = 'p';
                PlayerPos.Y += 1;

                Render();
            }
               
        }

        private void LEFTBTN_Click(object sender, EventArgs e)
        {
            if (IsMove(PlayerPos.X - 1, PlayerPos.Y))
            {
                int posx = PlayerPos.X;
                int posy = PlayerPos.Y;

                CurrentStageData[posy, posx] = ' ';
                CurrentStageData[posy, posx - 1] = 'p';
                PlayerPos.X -= 1;

                Render();
            }
            
        }

        private void RIGHTBTN_Click(object sender, EventArgs e)
        {
            if (IsMove(PlayerPos.X + 1, PlayerPos.Y))
            {
                int posx = PlayerPos.X;
                int posy = PlayerPos.Y;

                CurrentStageData[posy, posx] = ' ';
                CurrentStageData[posy, posx + 1] = 'p';
                PlayerPos.X += 1;

                Render();
            }
            
        }
    }
}
