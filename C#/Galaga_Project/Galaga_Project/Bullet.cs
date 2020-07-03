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
		public Point position;
		public readonly int Bulletspeed = 10;
		public readonly Image BulletImg = Properties.Resources.Galaga_310;
		public Bullet(Point pos)
		{
			position = new Point(pos.X, pos.Y);
		}
	}
}
