using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Galaga_Project
{
	class Enemy
	{
		private Point Position;
		public int posX
		{
			get	{ return Position.X; }
			set { Position.X = value; }
		}
		public int posY
		{
			get { return Position.Y; }
			set { Position.Y = value; }
		}
		public Image Img;
		public Enemy(Point pos, Image img)
		{
			Position = new Point(pos.X, pos.Y);
			Img = img;
		}
		public Enemy(Enemy enemy)
		{
			this.Position = enemy.Position;
			this.Img = enemy.Img;
		}

		public bool Hit = true;

		// 충돌처리 계산을 위해 호출되는 메소드
		public Rectangle GetRect()
		{
			return new Rectangle(Position, Img.Size);
		}
	}
	/// <summary>
	/// 몬스터 관리 클래스
	/// </summary>
	class EnemyControler
	{
		private static EnemyControler Instance = null;
		public static EnemyControler Inst
		{
			get
			{
				if (Instance == null)
					Instance = new EnemyControler();
				return Instance;
			}
		}
		public Enemy[,] enemyList = null;		// 몬스터 객체를 가진 메소드
		private List<Image> enemyImgList = new List<Image>();	// 이미지를 가지고 있는 리스트

		private Timer EnemyMoveTimer = null;    // 몬스터를 이동하기 위한 메소드

		private int ArrSizeY = 5;
		public int EnemyListSizeY
		{
			get { return ArrSizeY; }
		}
		private readonly int ArrSizeX = 10;
		public int EnemyListSizeX
		{
			get { return ArrSizeX; }
		}
		
		private int EnemyMoveSpeed = 10;		// 몬스터 이동 속도
		private bool EnemyTouchedWall = false;  // 몬스터가 벽에 닿았는지 체크하는 함수
		private Enemy RightLastEnemy;
		private Enemy LeftLastEnemy;

		private int StageCount = 1;
		public int stageCount
		{
			get { return StageCount; }
		}

		private int count = 0;
		private bool flag = false;
		/// <summary>
		/// 이미지 가져오는 메소드
		/// </summary>
		public void EnemyImageInit()
		{
			enemyImgList.Add(Properties.Resources.Galaga_170);
			enemyImgList.Add(Properties.Resources.Galaga_169);

			enemyImgList.Add(Properties.Resources.Galaga_126);
			enemyImgList.Add(Properties.Resources.Galaga_125);

			enemyImgList.Add(Properties.Resources.Galaga_134);
			enemyImgList.Add(Properties.Resources.Galaga_133);

			enemyImgList.Add(Properties.Resources.Galaga_178);
			enemyImgList.Add(Properties.Resources.Galaga_177);

			enemyImgList.Add(Properties.Resources.Galaga_96);
			enemyImgList.Add(Properties.Resources.Galaga_95);
		}

		/// <summary>
		/// EnemyControler 초기화 메소드
		/// </summary>
		public void EnemyInit()
		{
			enemyList = new Enemy[ArrSizeY, ArrSizeX];
			
			// 몬스터 생성
			for (int i = 0; i < ArrSizeY; i++)
			{
				for (int j = 0; j < ArrSizeX; j++)
				{
					int posX = 100 + enemyImgList[i].Width * j + 20 * j;
					int posY = 100 + (enemyImgList[i].Height * i) + (20 * i);
					Enemy temp = new Enemy(new Point( posX, posY), enemyImgList[i * 2]);

					if (i >= ArrSizeY - 1)
						temp.Hit = false;
					enemyList[i,j] = temp;
				}
			}

			RightLastEnemy = new Enemy(enemyList[0,9]);
			LeftLastEnemy = new Enemy(enemyList[0,0]);

			EnemyMoveTimer = new Timer();
			EnemyMoveTimer.Interval = 100;
			EnemyMoveTimer.Tick += EnemyMoveTimer_Tick;
			EnemyMoveTimer.Start();
		}

		public void StopTimer()
		{
			EnemyMoveTimer.Stop();
		}
		public void ReStartTimer()
		{
			StageCount += 1;
			EnemyMoveSpeed = (int)(EnemyMoveSpeed * 1.2f);
			EnemyMoveTimer.Start();
		}

		/// <summary>
		/// 벽과 충돌 했을때 호출되는 메소드
		/// </summary>
		private void EnemyMoveSwitching()
		{
			if (EnemyTouchedWall)
			{
				for (int i = 0; i < ArrSizeY; i++)
				{
					for (int j = 0; j < ArrSizeX; j++)
					{
						enemyList[i,j].posY += enemyList[i,j].Img.Height;
					}
				}
				EnemyMoveSpeed *= -1;
				EnemyTouchedWall = false;
			}
		}
		/// <summary>
		/// 몬스터 컨트롤러 타이머 이벤트 메소드
		/// </summary>
		private void EnemyMoveTimer_Tick(object sender, EventArgs e)
		{
			
			if (RightLastEnemy.posX + RightLastEnemy.Img.Width * 1.5f > Form1.clientSize.Width 
				|| LeftLastEnemy.posX < 0)
			{
				EnemyTouchedWall = true;
				EnemyMoveSwitching();
			}
			for (int i = 0; i < ArrSizeY; i++)
			{
				for (int j = 0; j < ArrSizeX; j++)
				{
					enemyList[i,j].posX += EnemyMoveSpeed;
				}
			}
			
			if(count++ >= 10)
			{
				count = 0;
				for (int i = 0; i < ArrSizeY; i++)
				{
					for (int j = 0; j < ArrSizeX; j++)
					{
						if(enemyList[i,j].Hit == false)
						{
							if (flag)
								enemyList[i, j].Img = enemyImgList[i * 2 + 1];
							else
								enemyList[i, j].Img = enemyImgList[i * 2];
						}	
					}
				}
				flag = !flag;
			}
			

			RightLastEnemy.posX += EnemyMoveSpeed;
			LeftLastEnemy.posX += EnemyMoveSpeed;
		}

		/// <summary>
		/// 외부에서 호출되는 렌더링 함수
		/// </summary>
		public void Rendering(PaintEventArgs e)
		{
			for (int i = 0; i < ArrSizeY; i++)
			{
				for (int j = 0; j < ArrSizeX; j++)
				{
					e.Graphics.DrawImage(enemyList[i,j].Img, enemyList[i,j].posX, enemyList[i,j].posY,
					enemyList[i,j].Img.Size.Width * 1.5f, enemyList[i,j].Img.Size.Height * 1.5f);
				}
			}
		}
	}
}
