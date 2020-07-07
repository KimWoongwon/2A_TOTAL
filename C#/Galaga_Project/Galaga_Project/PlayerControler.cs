using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
using System.Resources;

namespace Galaga_Project
{
	enum MoveState
	{
		NONE,
		RIGHT,
		LEFT
	}
	class Player
	{
		private Point Position = new Point(200, 500);	// 플레이어 위치값
		public Point position
		{
			get { return Position; }
			set { Position = value; }
		}
		public int PosX
		{
			get { return Position.X; }
			set { Position.X = value; }
		}
		public int PosY
		{
			get { return Position.Y; }
			set { Position.Y = value; }
		}
		private Image PlayerImage = Properties.Resources.Player;	// 플레이어 이미지
		public Image Img
		{
			get { return PlayerImage; }
			set { PlayerImage = value; }
		}
		private MoveState PlayerMoveState = MoveState.NONE;	// 플레이어 이동 상태
		public MoveState MoveState
		{
			get { return PlayerMoveState; }
			set { PlayerMoveState = value; }
		}
		
		private int PlayerHp = 2;						// 플레이어 HP
		public int Hp
		{
			get { return PlayerHp; }
			set { PlayerHp = value; }
		}
		private readonly int PlayerMovespeed = 5;		// 플레이어 이동속도
		public int Movespeed
		{
			get { return PlayerMovespeed; }
		}
	}
	// 플레이어 관리 싱글톤 클래스
	class PlayerControler
	{
		private static PlayerControler Instance = null;
		public static PlayerControler Inst
		{
			get
			{
				if (Instance == null)
					Instance = new PlayerControler();
				return Instance;
			}
		}
		public Player player = new Player();					// 현재 플레이어
		public List<Image> playerImgList = new List<Image>();	// 플레이어에 사용될 이미지 리스트
		public List<Bullet> bulletList = new List<Bullet>();	// 플레이어가 발사한 총알 관리 리스트
		public void PlayerImgListInit()
		{
			playerImgList.Add(Properties.Resources.Player2);
			playerImgList.Add(Properties.Resources.Player);
		}
		/// <summary>
		/// 플레이어가 맞았을때의 처리
		/// </summary>
		public void HitPlayer()
		{
			--player.Hp;
			if(player.Hp > 0)
			player.Img = playerImgList[player.Hp - 1];
		}

		/// <summary>
		/// 플레이어 렌더링
		/// </summary>
		public void Rendering(PaintEventArgs e)
		{
			// 불릿 렌더링
			foreach (Bullet item in bulletList)
				e.Graphics.DrawImage(item.Img, item.position.X, item.position.Y, item.Img.Size.Width * 1.5f, item.Img.Size.Height * 1.5f);
			// 플레이어 렌더링
			e.Graphics.DrawImage(player.Img, player.PosX, player.PosY, player.Img.Size.Width * 1.5f, player.Img.Size.Height * 1.5f);
		}
		public void KeyDown(KeyEventArgs e)
		{
			int pushTime = Environment.TickCount;
			// 플레이어의 움직임 상태를 변경해서 저장 후 처리
			if (e.KeyCode == Keys.Right)
			{
				player.MoveState = MoveState.RIGHT;
				return;
			}
			if (e.KeyCode == Keys.Left)
			{
				player.MoveState = MoveState.LEFT;
				return;
			}

			if (e.KeyCode == Keys.Space && pushTime - Form1.startTime >= 100)
			{
				Form1.startTime = pushTime;
				Bullet temp = new Bullet(player.position, Properties.Resources.PlayerBullet);
				bulletList.Add(temp); // bullet을 생성해서 리스트에 저장 후 처리
				return;
			}
		}
		public void KeyUp(KeyEventArgs e)
		{
			// 혹시나 다른키나 발사키(space)를 누를때 플레이어의 움직임이 멈추지 않도록 예외처리
			switch (e.KeyCode)
			{
				case Keys.Right:
				case Keys.Left:
					player.MoveState = MoveState.NONE;
					break;
			}
		}
		public void PlayerMove()
		{
			// 이동상태에 따라 움직임이 처리되는 부분
			if (player.MoveState == MoveState.RIGHT)
			{
				if (player.PosX + player.Img.Width * 1.5f < Form1.clientSize.Width)    // 화면 밖으로 나가지 않게 예외처리
					player.PosX += player.Movespeed;
			}
			if (player.MoveState == MoveState.LEFT)
			{
				if (player.PosX > 0)    // 화면 밖으로 나가지 않게 예외처리
					player.PosX -= player.Movespeed;
			}

			// 총알이 발사되면 무조건 위로만 간다.
			for (int i = bulletList.Count - 1; i >= 0; i--)
			{
				bulletList[i].PosY -= bulletList[i].Bulletspeed;
			}
		}
		/// <summary>
		/// 스테이지 클리어 및 리셋시 호출되는 메소드
		/// </summary>
		public void Reset()
		{
			player = new Player();
			bulletList.Clear();
		}
	}
}
