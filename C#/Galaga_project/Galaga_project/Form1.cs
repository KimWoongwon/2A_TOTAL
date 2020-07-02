using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Galaga_project
{
	public partial class Galaga : Form
	{
        Player player = null; 
		public Galaga()
		{
			InitializeComponent();
            player = Player.Instance;
        }

        private void Galaga_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Right)
                player.MoveState = PlayerState.RIGHT;
            if (e.KeyCode == Keys.Left)
                player.MoveState = PlayerState.LEFT;
        }

        private void Galaga_KeyUp(object sender, KeyEventArgs e)
        {
            if (player.MoveState != PlayerState.NONE)
                player.MoveState = PlayerState.NONE;
        }

        private void Galaga_Paint(object sender, PaintEventArgs e)
        {
            player.Rendering(e);
        }
    }
}
