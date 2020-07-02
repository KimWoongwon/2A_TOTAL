using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Galaga_project.Properties;

namespace Galaga_project
{
    public enum PlayerState
    {
        NONE,
        RIGHT,
        LEFT
    }
    class Player
    {
        private static Player Inst = null;
        static public Player Instance
        {
            get
            {
                if (Inst == null)
                {
                    Inst = new Player();
                    Inst.Init();
                }
                    
                return Inst;
            }
        }
        private PlayerState playerMoveState = PlayerState.NONE;
        public PlayerState MoveState
        {
            get { return playerMoveState; }
            set { MoveState = value; }
        }

        Point pos = new Point(300, 550);
        float MoveSpeed = 10f;
        
        Timer timer = null;
        Galaga main = new Galaga();
        public void Init()
        {
            timer = new Timer();
            timer.Interval = 50;
            timer.Tick += PlayerMove;
        }
        private Image GetPlayerImg()
        {
            return Resources.Galaga_17;
        }
        private void PlayerMove(object sender, EventArgs e)
        {
            if(playerMoveState == PlayerState.LEFT)
            {
                pos.X += (int)MoveSpeed;
            }
            main.Invalidate();
        }

        public void Rendering(PaintEventArgs e)
        {
            Image mImg = GetPlayerImg();
            e.Graphics.DrawImage(mImg, pos.X, pos.Y
                        , 32, 32);
        }
    }
}
