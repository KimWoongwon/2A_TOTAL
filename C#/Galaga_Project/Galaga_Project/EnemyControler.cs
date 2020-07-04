using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Galaga_Project
{
	class Enemy
	{
		public Point position;
		public Image Img;
		public Enemy(Point pos, Image img)
		{
			position = new Point(pos.X, pos.Y);
			Img = img;
		}
	}
	class EnemyControler
	{

		List<Enemy> enemyList = new List<Enemy>();		// 몬스터 객체를 가진 메소드
		List<Image> enemyImgList = new List<Image>();	// 이미지를 가지고 있는 리스트

		Timer EnemyMoveTimer = null;	// 몬스터를 이동하기 위한 메소드

		int EnemyMoveSpeed = 10;		// 몬스터 이동 속도
		bool EnemyTouchedWall = false;	// 몬스터가 벽에 닿았는지 체크하는 함수
		
		/// <summary>
		/// 이미지 가져오는 메소드
		/// </summary>
		private void EnemyImageInit()
		{
			enemyImgList.Add(Properties.Resources.Galaga_170);
			enemyImgList.Add(Properties.Resources.Galaga_126);
			enemyImgList.Add(Properties.Resources.Galaga_134);
			enemyImgList.Add(Properties.Resources.Galaga_178);
			enemyImgList.Add(Properties.Resources.Galaga_96);
		}
		/// <summary>
		/// 외부에서 타이머 시작시키려고 만든 메소드
		/// </summary>
		public void RuningEnemyControler()
		{
			EnemyMoveTimer.Start();
		}
		/// <summary>
		/// 몬스터 객체 생성 및 타이머 생성 메소드
		/// </summary>
		public void EnemyInit()
		{
			EnemyImageInit();
			// 몬스터 생성
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					int posX = 100 + enemyImgList[i].Width * j + 20 * j;
					int posY = 100 + (enemyImgList[i].Height * i) + (20 * i);
					Enemy temp = new Enemy(new Point( posX, posY), enemyImgList[i]);

					enemyList.Add(temp);
				}
			}
			EnemyMoveTimer = new Timer();
			EnemyMoveTimer.Interval = 100;
			EnemyMoveTimer.Tick += EnemyMoveTimer_Tick;
		}
		/// <summary>
		/// 벽과 충돌 했을때 호출되는 메소드
		/// </summary>
		private void EnemyMoveSwitching()
		{
			if (EnemyTouchedWall)
			{
				for (int i = enemyList.Count - 1; i >= 0; i--)
				{
					enemyList[i].position.Y += enemyList[i].Img.Height;
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
			if (enemyList[9].position.X + enemyList[9].Img.Width * 1.5f > Form1.clientSize.Width 
				|| enemyList[0].position.X < 0)
			{
				EnemyTouchedWall = true;
				EnemyMoveSwitching();
			}
			for (int i = enemyList.Count - 1; i >= 0; i--)
			{
				enemyList[i].position.X += EnemyMoveSpeed;
			}
		}

		/// <summary>
		/// 외부에서 호출되는 렌더링 함수
		/// </summary>
		public void Rendering(PaintEventArgs e)
		{
			for (int i = enemyList.Count - 1; i >= 0; i--)
			{
				e.Graphics.DrawImage(enemyList[i].Img, enemyList[i].position.X, enemyList[i].position.Y,
					enemyList[i].Img.Size.Width * 1.5f, enemyList[i].Img.Size.Height * 1.5f);
			}
		}
	}
}
