using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;


namespace Galaga_Project
{
	class Bullet
	{
		private Point Position;
		public Point position
		{
			get { return Position; }
		}
		public int PosY
		{
			get { return Position.Y; }
			set { Position.Y = value; }
		}
		public readonly int Bulletspeed = 10;
		public readonly Image Img = Properties.Resources.Galaga_310;
		public Bullet(Point pos)
		{
			Position = new Point(pos.X, pos.Y);
		}
		public Rectangle GetRect()
		{
			return new Rectangle(position, Img.Size);
		}
	}
}
