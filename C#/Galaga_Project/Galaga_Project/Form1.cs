using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Galaga_Project.Properties;



namespace Galaga_Project
{
    
	public partial class Form1 : Form
	{
        enum MoveState
        {
            NONE,
            RIGHT,
            LEFT
        }
        
        readonly int Movespeed = 5;
        readonly Image playerimg = Resources.Galaga_17;

        Point playerPos = new Point(300, 650);
        MoveState playerMoveState = MoveState.NONE;

        static List<Bullet> bulletList = new List<Bullet>();
        
        Timer UpdateTimer = null;
        Timer MoveTimer = null;

        public static Size clientSize;

        int startTime;
        bool CheckEnd = true;
        //Timer EnemyRegenTimer = null;

        //EnemyControler enemyControler = new EnemyControler();
        public Form1()
		{
			InitializeComponent();
            clientSize = ClientSize;
            startTime = Environment.TickCount;
            EnemyControler.Inst.EnemyImageInit();
            EnemyControler.Inst.EnemyInit();

            // 충돌처리 및 그리기 타이머
            UpdateTimer = new Timer();
            UpdateTimer.Interval = 2;
            UpdateTimer.Tick += UpdateTimer_Tick;
            UpdateTimer.Start();

            // 플레이어 이동 타이머
            MoveTimer = new Timer();
            MoveTimer.Interval = 2;
            MoveTimer.Tick += MoveTimer_Tick;
            MoveTimer.Start();

        }
        /// <summary>
		/// 이미지 렌더링 메소드
		/// </summary>
        void DirectRender(PaintEventArgs e)
        {

            // 불릿 렌더링
            foreach (Bullet item in bulletList)
                e.Graphics.DrawImage(item.Img, item.position.X, item.position.Y, item.Img.Size.Width * 1.5f, item.Img.Size.Height * 1.5f);
            // 플레이어 렌더링
            e.Graphics.DrawImage(playerimg, playerPos.X, playerPos.Y, playerimg.Size.Width * 1.5f, playerimg.Size.Height * 1.5f);

            EnemyControler.Inst.Rendering(e);
        }

        /// <summary>
        /// 총알과 몬스터의 충돌처리를 계산하는 메소드
        /// </summary>
        bool CheckHit(int bIndex, int eYIndex, int eXIndex)
        {
            if (EnemyControler.Inst.enemyList[eYIndex, eXIndex].Hit)
                return false;
            // 총알의 영역 계산
            Rectangle Bullet = bulletList[bIndex].GetRect();
            int MinbulletX = bulletList[bIndex].position.X;
            int MaxbulletX = bulletList[bIndex].position.X + bulletList[bIndex].Img.Width;
            int MinbulletY = bulletList[bIndex].position.Y;
            int MaxbulletY = bulletList[bIndex].position.Y + bulletList[bIndex].Img.Height;

            Rectangle Enemy = bulletList[bIndex].GetRect();
            int MinenemyX = EnemyControler.Inst.enemyList[eYIndex,eXIndex].posX;
            int MaxenemyX = EnemyControler.Inst.enemyList[eYIndex,eXIndex].posX + (int)(EnemyControler.Inst.enemyList[eYIndex,eXIndex].Img.Width * 1.5f) + 20;
            int MinenemyY = EnemyControler.Inst.enemyList[eYIndex,eXIndex].posY;
            int MaxenemyY = EnemyControler.Inst.enemyList[eYIndex,eXIndex].posY + (int)(EnemyControler.Inst.enemyList[eYIndex, eXIndex].Img.Height * 1.5f);

            if (MinbulletX > MinenemyX && MaxbulletX < MaxenemyX)
            {
                if (MinbulletY > MinenemyY && MaxbulletY < MaxenemyY)
                     return true;
            } 
            return false;
        }
        void BulletHitEnemy()
        {
            bool tempcheck = false;
            if (bulletList.Count > 0)
            { 
                for (int i = bulletList.Count - 1; i >= 0; i--)
                {
                    for (int y = 0; y < EnemyControler.Inst.EnemyListSizeY; y++)
                    {
                        for (int x = 0; x < EnemyControler.Inst.EnemyListSizeX; x++)
                        {
                            if (CheckHit(i, y, x))
                            {
                                bulletList.RemoveAt(i);
                                EnemyControler.Inst.enemyList[y,x].Hit = true;
                                EnemyControler.Inst.enemyList[y, x].Img = Resources.Empty;

                                if(y != 0)
                                    EnemyControler.Inst.enemyList[y - 1, x].Hit = false;

                                tempcheck = true;
                                break;
                            }
                        }
                        if (tempcheck)
                            break;
                    }
                }
            }
        }

        bool IsEnd()
        {
            for (int y = 0; y < EnemyControler.Inst.EnemyListSizeY; y++)
            {
                for (int x = 0; x < EnemyControler.Inst.EnemyListSizeX; x++)
                {
                    if (!EnemyControler.Inst.enemyList[y, x].Hit)
                        return false;
                }
            }
            return true;
        }

        void StopTimers()
        {
            UpdateTimer.Stop();
            MoveTimer.Stop();
            EnemyControler.Inst.StopTimer();
        }
        void ReStartTimers()
        {
            UpdateTimer.Start();
            MoveTimer.Start();
            EnemyControler.Inst.ReStartTimer();
        }

        // 타이머 이벤트 메소드
		#region
		/// <summary>
		/// 각종 움직임을 위한 타이머 이벤트 메소드
		/// </summary>
		private void MoveTimer_Tick(object sender, EventArgs e)
        {
            // 이동상태에 따라 움직임이 처리되는 부분
            if (playerMoveState == MoveState.RIGHT)
            {   
                if (playerPos.X + playerimg.Width * 1.5f < ClientSize.Width)    // 화면 밖으로 나가지 않게 예외처리
                    playerPos.X += Movespeed;
            }
            if (playerMoveState == MoveState.LEFT)
            {
                if (playerPos.X > 0)    // 화면 밖으로 나가지 않게 예외처리
                    playerPos.X -= Movespeed;
            }

            // 총알이 발사되면 무조건 위로만 간다.
            for (int i = bulletList.Count - 1; i >= 0; i--)
            {
                bulletList[i].PosY -= bulletList[i].Bulletspeed;
            }

            
        }

        /// <summary>
        /// 충돌처리 및 렌더링, 종료시점 체크를 위한 타이머 이벤트 메소드
        /// </summary>
        private void UpdateTimer_Tick(object sender, EventArgs e)
        {
            // 총알과 몬스터 충돌체크하는 메소드
            BulletHitEnemy();

            // 종료시점 체크 하는 부분
            if (IsEnd() && CheckEnd)
            {
                StopTimers();
                CheckEnd = false;
                if (MessageBox.Show("You Win!!! \n RePlay? or End?", "Congratulation!!", MessageBoxButtons.YesNo) == DialogResult.No)
                {
                    Application.Exit();
                }
                else
                {
                    EnemyControler.Inst.EnemyImageInit();
                    EnemyControler.Inst.EnemyInit();
                    bulletList.Clear();
                    ReStartTimers();
                    CheckEnd = true;
                }
                return;
            }
            
            Invalidate();
        }
		#endregion
        
        /// <summary>
        /// Invalidate() 메소드에서 호출되는 이벤트 메소드
        /// </summary>
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            DirectRender(e);
        }

        // 키입력 이벤트 메소드
        #region
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {

            int pushTime = Environment.TickCount;
            // 플레이어의 움직임 상태를 변경해서 저장 후 처리
            if (e.KeyCode == Keys.Right)
            {
                playerMoveState = MoveState.RIGHT;
                return;
            }
            if (e.KeyCode == Keys.Left)
            {
                playerMoveState = MoveState.LEFT;
                return;
            }

            if(e.KeyCode == Keys.Space && pushTime - startTime >= 300)
            {
                startTime = pushTime;
                Bullet temp = new Bullet(playerPos);
                bulletList.Add(temp); // bullet을 생성해서 리스트에 저장 후 처리
                return;
            }
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            // 혹시나 다른키나 발사키(space)를 누를때 플레이어의 움직임이 멈추지 않도록 예외처리
            switch (e.KeyCode)
            {
                case Keys.Right:
                case Keys.Left:
                    playerMoveState = MoveState.NONE;
                    break;
            }
        }
		#endregion 

	}
}
