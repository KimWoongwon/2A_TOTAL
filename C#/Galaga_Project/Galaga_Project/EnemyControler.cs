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
		private Point Position;			// 몬스터 위치
		public Point position
		{
			get { return Position; }
		}
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
		public Image Img;		// 몬스터 이미지
		public Enemy(Point pos, Image img)	// 생성자 구현
		{
			Position = new Point(pos.X, pos.Y);
			Img = img;
		}
		public Enemy(Enemy enemy)			// 복사생성자 구현
		{
			this.Position = enemy.Position;
			this.Img = enemy.Img;
		}

		public bool Hit = true;		// 맞았는지 체크하기 위한 변수
									// 초기값이 true인 이유는 첫번째줄을 제외한 나머지 몬스터는 총알에 맞지 않게 하기위함
		// 충돌처리 계산을 위해 호출되는 메소드
		public Rectangle GetRect()
		{
			return new Rectangle(Position, Img.Size);
		}
	}
	/// <summary>
	/// 몬스터 관리 싱글톤 클래스
	/// </summary>
	class EnemyControler
	{
		private static EnemyControler Instance = null;				// 싱글톤 이용위한 변수
		public static EnemyControler Inst							// 싱글톤 변수 프로퍼티
		{
			get
			{
				if (Instance == null)
					Instance = new EnemyControler();
				return Instance;
			}
		}
		public Enemy[,] enemyList = null;							// 몬스터 객체를 가진 메소드
		private List<Image> enemyImgList = new List<Image>();		// 이미지를 가지고 있는 리스트
		public List<Bullet> EnemyBulletList = new List<Bullet>();	// 몬스터가 발사한 총알을 관리하기 위한 리스트
		private Random random = new Random();						// 몬스터가 총알을 발사하는 확률을 위한 변수

		private int ArrSizeY;                   // 몬스터 array Y사이즈 
												//스테이지에 따라 몬스터 출현 개수가 결정
		public int EnemyListSizeY				// 몬스터 array Y사이즈 프로퍼티
		{
			get { return ArrSizeY; }
		}
		private readonly int ArrSizeX = 10;		// 몬스터 array X사이즈
		public int EnemyListSizeX				// 몬스터 array X사이즈 프로퍼티
		{
			get { return ArrSizeX; }
		}
		
		private int EnemyMoveSpeed = 10;		// 몬스터 이동 속도
		private bool EnemyTouchedWall = false;	// 몬스터가 벽에 닿았는지 체크하는 함수
		private Enemy RightLastEnemy;			// 벽에 닿았는지 검사를 위한 좌우 끝 몬스터 객체
		private Enemy LeftLastEnemy;

		private int StageCount = 1;				// 스테이지를 나타내기 위한 변수
		public int stageCount
		{
			get { return StageCount; }
		}
		private int Count = 0;					// 몬스터 애니메이션 및 몬스터 발사 총알 제한을 위한 카운트
		private bool flag = false;				// 몬스터 애니메이션 flag 변수

		/// <summary>
		/// 이미지 가져오는 메소드
		/// </summary>
		public void EnemyImageInit()
		{
			enemyImgList.Add(Properties.Resources.Enemy1_2);
			enemyImgList.Add(Properties.Resources.Enemy1_1);

			enemyImgList.Add(Properties.Resources.Enemy2_2);
			enemyImgList.Add(Properties.Resources.Enemy2_1);

			enemyImgList.Add(Properties.Resources.Enemy3_2);
			enemyImgList.Add(Properties.Resources.Enemy3_1);

			enemyImgList.Add(Properties.Resources.Enemy4_2);
			enemyImgList.Add(Properties.Resources.Enemy4_1);

			enemyImgList.Add(Properties.Resources.Enemy5_2);
			enemyImgList.Add(Properties.Resources.Enemy5_1);
		}

		/// <summary>
		/// EnemyControler 초기화 메소드
		/// </summary>
		public void EnemyInit()
		{
			ArrSizeY = StageCount;
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
		}

		/// <summary>
		/// 스테이지 클리어시 호출되는 메소드
		/// </summary>
		public void StageClear()
		{
			StageCount += 1;	// 스테이지 체크
			EnemyMoveSpeed = (int)(EnemyMoveSpeed * 1.2f);	// 스테이지에 따라 이동속도 증가
		}
		/// <summary>
		/// 스테이지 패배시 호출되는 메소드
		/// </summary>
		public void StageLose()
		{
			StageCount = 1;    // 스테이지 체크
			EnemyMoveSpeed = 10;  // 스테이지에 따라 이동속도 증가
		}

		/// <summary>
		/// 스테이지 클리어나 패배시 호출되는 메소드
		/// </summary>
		public void Reset()
		{
			EnemyBulletList.Clear(); // 기존 몬스터가 발사한 총알 삭제
			EnemyImageInit();
			EnemyInit();
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
		/// 외부에서 타이머 메소드 발생시 몬스터 관리를 위한 메소드
		/// </summary>
		public void EnemyMove()
		{
			
			// 몬스터 벽과 충돌시 아래로 이동 부분
			if (RightLastEnemy.posX + RightLastEnemy.Img.Width * 1.5f > Form1.clientSize.Width 
				|| LeftLastEnemy.posX < 0)
			{
				EnemyTouchedWall = true;
				EnemyMoveSwitching();
			}

			// 몬스터 이동
			for (int i = 0; i < ArrSizeY; i++)
			{
				for (int j = 0; j < ArrSizeX; j++)
				{
					enemyList[i,j].posX += EnemyMoveSpeed;
				}
			}

			// 총알 이동
			for (int i = EnemyBulletList.Count - 1; i >= 0; i--)
			{
				EnemyBulletList[i].PosY += EnemyBulletList[i].Bulletspeed;
			}
			
			if(Count++ >= 10)
			{
				Count = 0;
				// 일정 시간마다 몬스터가 총알을 발사하게끔 구현
				for (int i = 0; i < ArrSizeY; i++)
				{
					for (int j = 0; j < ArrSizeX; j++)
					{
						if (enemyList[i, j].Img != Properties.Resources.Empty && enemyList[i, j].Hit == false)
						{
							// 기본 10% 확률이며 스테이지에 따라 조금씩 증가
							if (random.Next(0, 100) <= 10 * (1 + ((float)StageCount /10)))
								EnemyBulletList.Add(new Bullet(enemyList[i, j].position, Properties.Resources.EnemyBullet));
						}
					}
				}
				
				// 이미지 스위칭으로 애니메이션 구현
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
			// 몬스터 렌더링
			for (int i = 0; i < ArrSizeY; i++)
			{
				for (int j = 0; j < ArrSizeX; j++)
				{
					e.Graphics.DrawImage(enemyList[i,j].Img, enemyList[i,j].posX, enemyList[i,j].posY,
					enemyList[i,j].Img.Size.Width * 1.5f, enemyList[i,j].Img.Size.Height * 1.5f);
				}
			}
			// 총알 렌더링
			for (int i = EnemyBulletList.Count - 1; i >= 0; i--)
			{
				e.Graphics.DrawImage(EnemyBulletList[i].Img, EnemyBulletList[i].position.X, EnemyBulletList[i].position.Y,
					EnemyBulletList[i].Img.Size.Width * 1.5f, EnemyBulletList[i].Img.Size.Height * 1.5f);
			}
		}
	}
}
