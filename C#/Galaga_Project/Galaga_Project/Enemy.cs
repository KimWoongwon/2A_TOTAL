using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Galaga_Project
{
	class Enemy
	{
		public Point position;
		public readonly Image Img = Properties.Resources.Galaga_170;
		public Timer moveTimer;
		public Enemy(Point pos)
		{
			position = new Point(pos.X, pos.Y);
			moveTimer = new Timer();
			moveTimer.Interval = 100;
			moveTimer.Tick += MoveTimer_Tick;
			moveTimer.Start();
		}

		private void MoveTimer_Tick(object sender, EventArgs e)
		{
			position.X += 2;
		}
	}
}
