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

        List<Bullet> bulletList = new List<Bullet>();
        Enemy enemy = new Enemy(new Point(100, 100));

        Timer UpdateTimer = null;
        Timer MoveTimer = null;
        //Timer EnemyRegenTimer = null;
        public Form1()
		{
			InitializeComponent();

            UpdateTimer = new Timer();
            UpdateTimer.Interval = 2;
            UpdateTimer.Tick += UpdateTimer_Tick;
            UpdateTimer.Start();

            MoveTimer = new Timer();
            MoveTimer.Interval = 2;
            MoveTimer.Tick += MoveTimer_Tick;
            MoveTimer.Start();

        }
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
                bulletList[i].position.Y -= bulletList[i].Bulletspeed;
            }
         
        }
        /// <summary>
        /// 충돌처리 및 렌더링을 위한 타이머 이벤트 메소드
        /// </summary>
        private void UpdateTimer_Tick(object sender, EventArgs e)
        {
            // 총알 사라지는 부분 처리. 오브젝트 풀의 구현 가능성?

            // 총알이 화면 위로 사라지면 삭제
            for (int i = bulletList.Count - 1; i >= 0; i--)
            {
                if (bulletList[i].position.Y + bulletList[i].Img.Height < 0)
                    bulletList.RemoveAt(i);
            }

            // 충돌처리 들어갈 부분
            Invalidate();
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
            e.Graphics.DrawImage(enemy.Img, enemy.position.X, enemy.position.Y, enemy.Img.Size.Width * 1.5f, enemy.Img.Size.Height * 1.5f);
        }

        /// <summary>
        /// Invalidate() 메소드에서 호출되는 이벤트 메소드
        /// </summary>
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            DirectRender(e);
        }

        // 키입력 이벤트 처리
        #region
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
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
            if(e.KeyCode == Keys.Space)
            {
                bulletList.Add(new Bullet(playerPos)); // bullet을 생성해서 리스트에 저장 후 처리
                return;
            }
            Debug.WriteLine("Push any Key");
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
