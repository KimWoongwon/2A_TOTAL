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
using System.Resources;
using System.Globalization;
using Galaga_Project.Properties;



namespace Galaga_Project
{
    
	public partial class Form1 : Form
	{
        private char[] StageString = { 'S', 'T', 'A', 'G', 'E', ':' };
        private char[] ScoreString = { 'S', 'C', 'O', 'R', 'E', ':' };
        private int Score = 0;
        private Timer FixedUpdateTimer = null;  // 총알 충돌처리 및 그리기, 종료체크 타이머
        private Timer PlayerMoveTimer = null;   // 플레이어를 이동하기 위한 타이머
        private Timer EnemyMoveTimer = null;    // 몬스터를 이동하기 위한 타이머

        public static Size clientSize;          // 몬스터가 벽과 충돌했는지 검사하기 위한 static 변수

        public static int startTime;            // 총알의 발사 속도를 제한하기 위한 static 변수
        private bool CheckEnd = true;           // FixedUpdate 중 종료체크를 위한 변수
        private int Hpregen = 0;

        EnemyControler EControl = EnemyControler.Inst;  // 싱글톤 클래스 이용을 위한 변수
        PlayerControler PControl = PlayerControler.Inst;

        ResourceManager rm = Resources.ResourceManager;

        public Form1()
		{
			InitializeComponent();
            // 플레이어 리스트 이니셜라이즈
            PControl.PlayerImgListInit();
            // 몬스터 관련 이니셜라이즈
            EControl.EnemyImageInit();
            EControl.EnemyInit();

            // 클라이언트 관련 할당 (외부에서 사용)
            clientSize = ClientSize;
            startTime = Environment.TickCount;



            // 충돌처리 및 그리기 타이머
            FixedUpdateTimer = new Timer();
            FixedUpdateTimer.Interval = 2;
            FixedUpdateTimer.Tick += FixedUpdateTimer_Tick;
            FixedUpdateTimer.Start();

            // 플레이어 이동 타이머
            PlayerMoveTimer = new Timer();
            PlayerMoveTimer.Interval = 2;
            PlayerMoveTimer.Tick += PlayerMoveTimer_Tick;
            PlayerMoveTimer.Start();

            // 몬스터 이동 타이머
            EnemyMoveTimer = new Timer();
            EnemyMoveTimer.Interval = 50;
            EnemyMoveTimer.Tick += EnemyMoveTimer_Tick;
            EnemyMoveTimer.Start();

        }

        void UIRendering(PaintEventArgs e)
        {
            e.Graphics.DrawLine(new Pen(Color.Red, 1), 0, 470, ClientSize.Width, 470);

            StageRendering(e);
            ScoreRendering(e);
        }

        void ScoreRendering(PaintEventArgs e)
        {
            Image Img;
            int tempScore = Score;
            int div = 100000000;

            int Length = ScoreString.Length;
            for (int i = 0; i < Length; i++)
            {
                Img = (Bitmap)rm.GetObject(string.Format("Char_{0}", ScoreString[i]));
                e.Graphics.DrawImage(Img, 250 + i * Img.Width, 10, Img.Size.Width, Img.Size.Height);
            }
            
            for(int i = 0; i<8; i++)
            {
                Img = (Bitmap)rm.GetObject(string.Format("Number_{0}", tempScore / div));
                e.Graphics.DrawImage(Img, 250 + (Length++) * Img.Width, 10, Img.Size.Width, Img.Size.Height);
                tempScore = tempScore % div;
                div = div / 10;
            }
            Img = (Bitmap)rm.GetObject(string.Format("Number_{0}", Score % 10));
            e.Graphics.DrawImage(Img, 250 + Length * Img.Width, 10, Img.Size.Width, Img.Size.Height);
        }

        void StageRendering(PaintEventArgs e)
        {
            for (int i = 0; i < StageString.Length; i++)
            {
                Image CharImg = (Bitmap)rm.GetObject(string.Format("Char_{0}", StageString[i]));
                e.Graphics.DrawImage(CharImg, 10 + i * CharImg.Width, 10, CharImg.Size.Width, CharImg.Size.Height);
            }
            Image Img = (Bitmap)rm.GetObject(string.Format("Number_{0}", EControl.stageCount / 10));
            e.Graphics.DrawImage(Img, 10 + StageString.Length * Img.Width, 10, Img.Size.Width, Img.Size.Height);
            Img = (Bitmap)rm.GetObject(string.Format("Number_{0}", EControl.stageCount % 10));
            e.Graphics.DrawImage(Img, 10 + (StageString.Length + 1) * Img.Width, 10, Img.Size.Width, Img.Size.Height);
        }

        // 충돌 관련 메소드
		#region
		/// <summary>
		/// 플레이어가 발사한 총알과 몬스터의 충돌처리를 계산하는 메소드
		/// </summary>
		bool CheckHit(int bIndex, int eYIndex, int eXIndex)
        {
            if (!EControl.enemyList[eYIndex, eXIndex].Hit)
                return false;
            // 총알의 영역 계산
            int MinbulletX = PControl.bulletList[bIndex].position.X;
            int MaxbulletX = PControl.bulletList[bIndex].position.X + PControl.bulletList[bIndex].Img.Width;
            int MinbulletY = PControl.bulletList[bIndex].position.Y;
            int MaxbulletY = PControl.bulletList[bIndex].position.Y + PControl.bulletList[bIndex].Img.Height;

            // 몬스터의 영역 계산
            int MinenemyX = EControl.enemyList[eYIndex,eXIndex].posX - 10;
            int MaxenemyX = EControl.enemyList[eYIndex,eXIndex].posX + (int)(EControl.enemyList[eYIndex,eXIndex].NowImg.Width * 1.5f) + 10;
            int MinenemyY = EControl.enemyList[eYIndex,eXIndex].posY;
            int MaxenemyY = EControl.enemyList[eYIndex,eXIndex].posY + (int)(EControl.enemyList[eYIndex, eXIndex].NowImg.Height * 1.5f);

            // AABB 충돌 처리 계산
            if (MinbulletX > MinenemyX && MaxbulletX < MaxenemyX)
            {
                if (MinbulletY > MinenemyY && MaxbulletY < MaxenemyY)
                     return true;
            } 
            return false;
        }
        /// <summary>
        /// 몬스터가 발사한 총알과 플레이어의 충돌처리를 계산하는 메소드
        /// </summary>
        bool CheckHit(int bIndex)
        {
            // 총알의 영역 계산
            int MinbulletX = EControl.EnemyBulletList[bIndex].position.X;
            int MaxbulletX = EControl.EnemyBulletList[bIndex].position.X + EControl.EnemyBulletList[bIndex].Img.Width;
            int MinbulletY = EControl.EnemyBulletList[bIndex].position.Y;
            int MaxbulletY = EControl.EnemyBulletList[bIndex].position.Y + EControl.EnemyBulletList[bIndex].Img.Height;

            // 플레이어의 영역 계산
            int MinPlayerX = PControl.player.PosX - 10;
            int MaxPlayerX = PControl.player.PosX + (int)(PControl.player.Img.Size.Width * 1.5f) + 10;
            int MinPlayerY = PControl.player.PosY;
            int MaxPlayerY = PControl.player.PosY + (int)(PControl.player.Img.Size.Height * 1.5f);

            // AABB 충돌 처리 계산
            if (MinbulletX > MinPlayerX && MaxbulletX < MaxPlayerX)
            {
                if (MinbulletY > MinPlayerY && MaxbulletY < MaxPlayerY)
                    return true;
            }
            return false;
        }
        /// <summary>
        /// 플레이어가 발사한 총알과 몬스터간의 충돌여부 검사후 처리를 담당하는 메소드
        /// </summary>
        void BulletHitEnemy()
        {
            
            bool tempcheck = false;
            if (PControl.bulletList.Count > 0)
            { 
                // 루프문을 돌며 총알과 적의 충돌 여부 검사
                for (int i = PControl.bulletList.Count - 1; i >= 0; i--)
                {
                    for (int y = 0; y < EControl.EnemyListSizeY; y++)
                    {
                        for (int x = 0; x < EControl.EnemyListSizeX; x++)
                        {
                            if (CheckHit(i, y, x))
                            {
                                // 충돌시 해당 총알을 삭제
                                PControl.bulletList.RemoveAt(i);

                                // 몬스터의 충돌시 몬스터 삭제 대신 충돌했다고 처리
                                EControl.enemyList[y, x].Hit = false;
                                EControl.enemyList[y, x].IsHit = true;

                                // 충돌한 몬스터의 위에있는 몬스터와 충돌할 수 있도록 변수 변경
                                if (y != 0)
                                    EControl.enemyList[y - 1, x].Hit = true;

                                Score += (int)(100 * EControl.stageCount * 1.5f);

                                // 전체 루프문 탈출
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
        /// <summary>
        /// 몬스터가 발사한 총알과 플레이어간의 충돌여부 검사후 처리를 담당하는 메소드
        /// </summary>
        void BulletHitPlayer()
        {
            // 루프문을 돌며 플레이어와 몬스터가 발사한 총알간의 충돌 여부 검사
            if (EControl.EnemyBulletList.Count > 0)
            {
                for (int i = EControl.EnemyBulletList.Count - 1; i >= 0; i--)
                {
                    if (CheckHit(i))
                    {
                        // 충돌시 해당 총알 제거
                        EControl.EnemyBulletList.RemoveAt(i);
                        // 충돌했을시 처리 메소드 호출
                        PControl.HitPlayer();
                        
                        break;
                    }
                }
            }
        }
		#endregion

		// 종료시점 체크 메소드
		#region
		/// <summary>
		/// 스테이지 클리어 체크 메소드
		/// </summary>
		bool IsClear()
        {
            // 몬스터 전체가 모두 총알에 맞았다면 트루 리턴
            for (int y = 0; y < EControl.EnemyListSizeY; y++)
            {
                for (int x = 0; x < EControl.EnemyListSizeX; x++)
                {
                    if (!EControl.enemyList[y, x].IsHit)
                        return false;
                }
            }
            return true;
        }
        /// <summary>
        /// 플레이어가 죽었을때 체크 메소드
        /// </summary>
        bool IsEnd()
        {
            if (PControl.player.Hp < 0)
                return true;

            Enemy temp = EControl.GetFirstEnemy();
            if (temp != null)
            {
                if (temp.posY + temp.NowImg.Size.Height > 470)
                    return true;
            }

            return false;
        }
		#endregion

		// 타이머 관리 메소드
		#region
		/// <summary>
		/// 스테이지 클리어 혹은 리셋시 선택 시간동안 타이머가 계속 가지않도록 처리 메소드
		/// </summary>
		void StopTimers()
        {
            FixedUpdateTimer.Stop();
            PlayerMoveTimer.Stop();
            EnemyMoveTimer.Stop();
        }

        /// <summary>
        /// 스테이지 클리어 혹은 리셋시 계속하기 위해 선택시 타이머 재시작 처리 메소드
        /// </summary>
        void ReStartTimers()
        {
            FixedUpdateTimer.Start();
            PlayerMoveTimer.Start();
            EnemyMoveTimer.Start();
        }
		#endregion

		// 타이머 이벤트 메소드
		#region
		/// <summary>
		/// 플레이어 움직임을 위한 타이머 이벤트 메소드
		/// </summary>
		private void PlayerMoveTimer_Tick(object sender, EventArgs e)
        {
            // PlayerControler 내부의 움직임 처리를 위한 메소드 호출
            PControl.PlayerMove();
        }
        /// <summary>
        /// 몬스터 움직임을 위한 타이머 이벤트 메소드
        /// </summary>
        private void EnemyMoveTimer_Tick(object sender, EventArgs e)
        {
            EControl.EnemyMove();
        }
        /// <summary>
        /// 충돌처리 및 렌더링, 종료시점 체크를 위한 타이머 이벤트 메소드
        /// </summary>
        private void FixedUpdateTimer_Tick(object sender, EventArgs e)
        {
            // 총알과 몬스터 충돌체크하는 메소드
            BulletHitEnemy();
            // 총알과 플레이어 충돌체크하는 메소드
            BulletHitPlayer();


            // HP 리젠 처리
            if(PControl.player.Hp == 1)
            {
                ++Hpregen;
                if (Hpregen >= 250)
                {
                    Hpregen = 0;
                    PControl.player.Hp = 2;
                    PControl.player.Img = PControl.playerImgList[PControl.player.Hp - 1];
                }
            }

            // 스테이지 클리어 시점 체크 하는 부분
            if (IsClear() && CheckEnd)
            {
                StopTimers();
                CheckEnd = false;
                EControl.StageClear();
                EControl.Reset();
                PControl.Reset();
                ReStartTimers();
                CheckEnd = true;
                return;
            }
            // 플레이어 사망 시점 체크 하는 부분
            if (IsEnd() && CheckEnd)
            {
                StopTimers();
                CheckEnd = false;
                DialogResult Result = MessageBox.Show("GameOver! \n ReStart? or End?", "GameOver", MessageBoxButtons.YesNo);
                // 사망시 메시지 박스 출력
                if (Result == DialogResult.No)
                {
                    Application.Exit();
                }
                else
                {
                    // 스테이지 레벨, 몬스터, 플레이어 초기화
                    EControl.StageLose();
                    EControl.Reset();
                    PControl.Reset();
                    ReStartTimers();
                    CheckEnd = true;
                }
                return;
            }


            Invalidate();
        }
        #endregion

        // Form 이벤트 메소드
        #region
        /// <summary>
        /// Invalidate() 메소드에서 호출되는 이벤트 메소드
        /// 플레이어와 몬스터 컨트롤러의 렌더링 메소드 호출
        /// </summary>
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            UIRendering(e);
            
            EControl.Rendering(e);
            PControl.Rendering(e);
        }

        /// <summary>
        /// 키다운시 플레이어 컨트롤의 메소드 호출
        /// </summary>
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            PControl.KeyDown(e);
        }

        /// <summary>
        /// 키 업시 플레이어 컨트롤의 메소드 호출
        /// </summary>
        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            PControl.KeyUp(e);
        }
		#endregion 

	}
}

