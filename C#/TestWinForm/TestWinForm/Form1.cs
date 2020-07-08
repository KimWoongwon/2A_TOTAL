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

    public enum E_DirectionType
    {
        UP,
        Right,
        Down,
        Left
    }
    

    public partial class Form1 : Form
    {
        // 상수
        public static readonly Size GameImageSize = new Size(30, 30);



        // 로직에 관련된 부분
        // update
        // 이동, 충돌, 


        // 이미지는 이미지대로
        // render


        // 0 = wall, x = box, p= player, .=goal
        string[] StageData = {
                  "0000000000000000"
                , "0   0  00      0"
                , "0     x x     .0"
                , "0     p        0"
                , "0    0      .  0"
                , "0              0"
                , "0000000000000000"
        };

        char[,] CurrentStageData = null; // 0, . // 스테이지 관련
        char[,] CurrentBOXStageData = null; // x, p // 박스와 플레이어 관련
        PictureBox[,] m_CurrentPicArr = null;
        Point m_PlayerPos = new Point();
        E_DirectionType m_PlayerDirecton = E_DirectionType.Down;


        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        PictureBox CreatePictureBox()
        {
            // 생성
            PictureBox picimage = new PictureBox();
            picimage.Size = GameImageSize;
            picimage.SizeMode = PictureBoxSizeMode.StretchImage;
            //this.Controls.Add(picimage);

            return picimage;
        }

        Image GetPlayerNBOXTypeImg(int p_x, int p_y)
        {
            if (CurrentBOXStageData[p_y, p_x] == 'x')
                return Resources.Crate_Beige;

            if (CurrentBOXStageData[p_y, p_x] == 'p')
            {
                switch (m_PlayerDirecton)
                {
                    case E_DirectionType.UP:
                        return Resources.Character7;
                        break;
                    case E_DirectionType.Right:
                        return Resources.Character2;
                        break;
                    case E_DirectionType.Down:
                        return Resources.Character4;
                        break;
                    case E_DirectionType.Left:
                        return Resources.Character1;
                        break;
                    default:
                        break;
                }
            }

            return null;
        }

        Image GetStageTypeImg(int p_x, int p_y )
        {
            if(CurrentStageData[p_y,p_x] == 'x')
                return Resources.Crate_Beige;

            if (CurrentStageData[p_y,p_x] == '.')
                return Resources.EndPoint_Beige;

            if (CurrentStageData[p_y,p_x] == 'p')
            {
                switch (m_PlayerDirecton)
                {
                    case E_DirectionType.UP:
                        return Resources.Character7;
                        break;
                    case E_DirectionType.Right:
                        return Resources.Character2;
                        break;
                    case E_DirectionType.Down:
                        return Resources.Character4;
                        break;
                    case E_DirectionType.Left:
                        return Resources.Character1;
                        break;
                    default:
                        break;
                }
            }

            if (CurrentStageData[p_y,p_x] == '0')
                return Resources.Wall_Brown;

            return Resources.Ground_Grass;
        }

        
        void Render()
        {
            return;

            int StageSizeY = StageData.Length;
            int StageSizeX = StageData[0].Length;
            
            for (int y = 0; y < StageSizeY; y++)
            {
                for (int x = 0; x < StageSizeX; x++)
                {
                    PictureBox picimage = m_CurrentPicArr[y, x];// CreatePictureBox();

                    picimage.Image = GetStageTypeImg(x, y);

                    // 위치
                    picimage.Location = new Point(x * GameImageSize.Width
                                            , y * GameImageSize.Height);
                }
            }
        }

        Size m_CurrentStageSize = new Size();
        void Init()
        {
            if(m_CurrentPicArr != null)
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


            m_CurrentStageSize.Height = StageData.Length;
            m_CurrentStageSize.Width = StageData[0].Length;

            CurrentStageData = new char[m_CurrentStageSize.Height, m_CurrentStageSize.Width];
            CurrentBOXStageData = new char[m_CurrentStageSize.Height, m_CurrentStageSize.Width];
            m_CurrentPicArr = new PictureBox[m_CurrentStageSize.Height, m_CurrentStageSize.Width];

            m_PlayerPos.X = -1;
            m_PlayerPos.Y = -1;

            for (int y = 0; y < m_CurrentStageSize.Height; y++)
            {
                for (int x = 0; x < m_CurrentStageSize.Width; x++)
                {
                    CurrentStageData[y, x] = ' ';
                    CurrentBOXStageData[y, x] = ' ';
                    if (StageData[y][x] == 'p') // 플레이어
                    {
                        CurrentBOXStageData[y, x] = StageData[y][x];
                        m_PlayerPos.X = x;
                        m_PlayerPos.Y = y;
                    }
                    else if(StageData[y][x] == 'x') // 박스
                    {
                        CurrentBOXStageData[y, x] = StageData[y][x];
                    }
                    else // 기타벽, 골인지점
                    {
                        CurrentStageData[y, x] = StageData[y][x];
                    }

                    PictureBox picimage = CreatePictureBox();
                    picimage.Name = string.Format("{0}_{1}", x, y);

                    m_CurrentPicArr[y, x] = picimage;
                }
            }


        }


        public Form1()
        {
            InitializeComponent();
            Init();
            Render();

        }


       


        bool ISOverStage(int p_x, int p_y)
        {
            if (p_x < 0 || m_CurrentStageSize.Width <= p_x )
                return true;
            if (p_y < 0 || m_CurrentStageSize.Height <= p_y )
                return true;

            return false;
        }

        bool ISBoxMove(int p_x, int p_y)
        {
            if (ISOverStage(p_x, p_y))
                return false;

            if (CurrentStageData[p_y, p_x] == '0')
                return false;

            if (CurrentBOXStageData[p_y, p_x] == 'x')
                return false;

            return true;
        }
        bool ISMove(int p_x, int p_y)
        {
            if ( ISOverStage(p_x, p_y) )
                return false;

            if (CurrentStageData[p_y, p_x] == '0')
                return false;

            return true;
        }

        bool ISBox(int p_x, int p_y)
        {
            if (ISOverStage(p_x, p_y))
                return false;

            return CurrentBOXStageData[p_y, p_x] == 'x';
        }

        void MoveBox(int p_x, int p_y, int p_mx, int p_my)
        {
            CurrentBOXStageData[p_my, p_mx] = 'x';
            CurrentBOXStageData[p_y, p_x] = ' ';
        }

        private void UPBTN_Click(object sender, EventArgs e)
        {
            m_PlayerDirecton = E_DirectionType.UP;

            if (ISMove(m_PlayerPos.X, m_PlayerPos.Y - 1))
            {
                int posx = m_PlayerPos.X;
                int posy = m_PlayerPos.Y;

                if ( ISBox(posx, posy - 1) )
                {
                    if( ISBoxMove(m_PlayerPos.X, m_PlayerPos.Y - 2))
                    {
                        MoveBox(posx, posy - 1, posx, posy - 2);

                        CurrentBOXStageData[posy, posx] = ' ';
                        CurrentBOXStageData[posy - 1, posx] = 'p';
                        m_PlayerPos.Y -= 1;
                    }
                }
                else
                {
                    CurrentBOXStageData[posy, posx] = ' ';
                    CurrentBOXStageData[posy - 1, posx] = 'p';
                    m_PlayerPos.Y -= 1;
                }
            }

            //Render();
            this.Invalidate();
        }

        private void DownBTN_Click(object sender, EventArgs e)
        {
            m_PlayerDirecton = E_DirectionType.Down;

            if ( ISMove(m_PlayerPos.X, m_PlayerPos.Y + 1) )
            {
                //int posx = m_PlayerPos.X;
                //int posy = m_PlayerPos.Y;

                //CurrentStageData[posy, posx] = ' ';
                //CurrentStageData[posy + 1, posx] = 'p';
                //m_PlayerPos.Y += 1;

                int posx = m_PlayerPos.X;
                int posy = m_PlayerPos.Y;

                if (ISBox(posx, posy + 1))
                {
                    if (ISBoxMove(m_PlayerPos.X, m_PlayerPos.Y + 2))
                    {
                        MoveBox(posx, posy + 1, posx, posy + 2);

                        CurrentBOXStageData[posy, posx] = ' ';
                        CurrentBOXStageData[posy + 1, posx] = 'p';
                        m_PlayerPos.Y += 1;
                    }
                }
                else
                {
                    CurrentBOXStageData[posy, posx] = ' ';
                    CurrentBOXStageData[posy + 1, posx] = 'p';
                    m_PlayerPos.Y += 1;
                }


            }

            Render();
            this.Invalidate();
        }

        private void RightBTN_Click(object sender, EventArgs e)
        {
            m_PlayerDirecton = E_DirectionType.Right;

            if (ISMove(m_PlayerPos.X + 1, m_PlayerPos.Y))
            {
                //int posx = m_PlayerPos.X;
                //int posy = m_PlayerPos.Y;

                //CurrentStageData[posy, posx] = ' ';
                //CurrentStageData[posy, posx + 1] = 'p';
                //m_PlayerPos.X += 1;

                int posx = m_PlayerPos.X;
                int posy = m_PlayerPos.Y;

                if (ISBox(posx + 1, posy ))
                {
                    if (ISBoxMove(m_PlayerPos.X + 2, m_PlayerPos.Y))
                    {
                        MoveBox(posx + 1, posy, posx + 2, posy);

                        CurrentBOXStageData[posy, posx] = ' ';
                        CurrentBOXStageData[posy, posx + 1] = 'p';
                        m_PlayerPos.X += 1;
                    }
                }
                else
                {
                    CurrentBOXStageData[posy, posx] = ' ';
                    CurrentBOXStageData[posy, posx + 1] = 'p';
                    m_PlayerPos.X += 1;
                }


            }

            Render();
            this.Invalidate();
        }

        private void LeftBTN_Click(object sender, EventArgs e)
        {
            m_PlayerDirecton = E_DirectionType.Left;

            if (ISMove(m_PlayerPos.X - 1, m_PlayerPos.Y))
            {
                //int posx = m_PlayerPos.X;
                //int posy = m_PlayerPos.Y;

                //CurrentStageData[posy, posx] = ' ';
                //CurrentStageData[posy, posx - 1] = 'p';
                //m_PlayerPos.X -= 1;


                int posx = m_PlayerPos.X;
                int posy = m_PlayerPos.Y;

                if (ISBox(posx - 1, posy))
                {
                    if (ISBoxMove(m_PlayerPos.X - 2, m_PlayerPos.Y))
                    {
                        MoveBox(posx - 1, posy, posx - 2, posy);

                        CurrentBOXStageData[posy, posx] = ' ';
                        CurrentBOXStageData[posy, posx - 1] = 'p';
                        m_PlayerPos.X -= 1;
                    }
                }
                else
                {
                    CurrentBOXStageData[posy, posx] = ' ';
                    CurrentBOXStageData[posy, posx - 1] = 'p';
                    m_PlayerPos.X -= 1;
                }

            }

            Render();
            this.Invalidate();
        }


        // 출처: https://hbisland.tistory.com/entry/c-더블-버퍼링 [아이쿠 허리야 !!]
        protected override void OnPaintBackground(PaintEventArgs e)
        {
            base.OnPaintBackground(e);
            // 이곳에서 백버퍼를 지우지 않도록 하고 다시 처음부터 그리는 방식으로 처리해하면됨
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
                    Point pos = new Point(x * GameImageSize.Width
                                            , y * GameImageSize.Height);
                    e.Graphics.DrawImage(tempimg, pos.X, pos.Y
                        , GameImageSize.Width, GameImageSize.Height);
                }
            }


            for (int y = 0; y < StageSizeY; y++)
            {
                for (int x = 0; x < StageSizeX; x++)
                {
                    Image tempimg = GetPlayerNBOXTypeImg(x, y);
                    if (tempimg == null)
                        continue;

                    // 위치
                    Point pos = new Point(x * GameImageSize.Width
                                            , y * GameImageSize.Height);
                    e.Graphics.DrawImage(tempimg, pos.X, pos.Y
                        , GameImageSize.Width, GameImageSize.Height);
                }
            }
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            DirectRender(e);

        }

        private void ResetBTN_Click(object sender, EventArgs e)
        {
            Init();
            //Render();
            this.Invalidate();

        }

        private void EditorBTN_Click(object sender, EventArgs e)
        {
            EditorForm editform = new EditorForm(StageData);
            //editform.SetMapData( StageData );
            if ( editform.ShowDialog() == DialogResult.OK)
            {
                StageData = editform.GetEditorMapData();

                Init();
                Invalidate();
            }
        }
    }
}
