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



namespace SlidePuzzle
{
	public enum MoveTo
	{
		DONOT = -1,
		UP = 0,
		DOWN,
		LEFT,
		RIGHT
	}
	public partial class Form1 : Form
	{
		Point player = new Point(3, 3);
		const int MapSizeX = 4;
		const int MapSizeY = 4;
		const int ImageSize = 125;
		List<Image> ImageList = new List<Image> { };
		List<MoveTo> preMoveList = new List<MoveTo> { };

		int[,] Map = null;
		int[,] result = null;
		PictureBox m_tempImage = null;
		Button button = null;
		Random rand = new Random();

		PictureBox[,] PictureArray = null;
		public Form1()
		{
			InitializeComponent();
			GameRun();
		}
		void GameRun()
		{
			Map_Initalize();
			List_Initalize();
			
			if (PictureArray != null)
			{
				foreach (var item in PictureArray)
				{
					this.Controls.Remove(item);
				}
			}
			PictureArray = null;

			PictureArray = new PictureBox[MapSizeY, MapSizeX];

			Image_Initalize();
			for (int i = 0; i < 100; i++)
				Setting();
			preMoveList.Clear();
			Button_Initalize();
			
		}
		void Map_Initalize()
		{
			Map = new int[MapSizeY, MapSizeX];
			result = new int[MapSizeY, MapSizeX];
			for (int y = 0; y < MapSizeY; y++)
			{
				for (int x = 0; x < MapSizeX; x++)
				{
					Map[y, x] = y * MapSizeY + x;
					result[y, x] = y * MapSizeY + x;
				}
			}
		}
		void List_Initalize()
		{
			ImageList.Add(Properties.Resources.Tiger_01);
			ImageList.Add(Properties.Resources.Tiger_02);
			ImageList.Add(Properties.Resources.Tiger_03);
			ImageList.Add(Properties.Resources.Tiger_04);
			ImageList.Add(Properties.Resources.Tiger_05);
			ImageList.Add(Properties.Resources.Tiger_06);
			ImageList.Add(Properties.Resources.Tiger_07);
			ImageList.Add(Properties.Resources.Tiger_08);
			ImageList.Add(Properties.Resources.Tiger_09);
			ImageList.Add(Properties.Resources.Tiger_10);
			ImageList.Add(Properties.Resources.Tiger_11);
			ImageList.Add(Properties.Resources.Tiger_12);
			ImageList.Add(Properties.Resources.Tiger_13);
			ImageList.Add(Properties.Resources.Tiger_14);
			ImageList.Add(Properties.Resources.Tiger_15);
			ImageList.Add(Properties.Resources.Empty);

			if (preMoveList.Count != 0)
				preMoveList.Clear();

			if (preMoveList.Count == 0)
				preMoveList.Add(MoveTo.DONOT);
		}
		void Image_Initalize()
		{
			for (int y = 0; y < MapSizeY; y++)
			{
				for (int x = 0; x < MapSizeX; x++)
				{
					m_tempImage = new PictureBox();
					m_tempImage.Image = ImageList[Map[y, x]];
					m_tempImage.Location = new System.Drawing.Point(x * ImageSize + 20, y * ImageSize + 20);
					//m_tempImage.Name = string.Format($"{x},{y}");
					m_tempImage.Size = new System.Drawing.Size(ImageSize - 3, ImageSize - 3);
					m_tempImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
					m_tempImage.TabIndex = 0;
					m_tempImage.TabStop = false;

					PictureArray[y, x] = m_tempImage;

					this.Controls.Add(m_tempImage);
				}
			}
		}
		void Button_Initalize()
		{
			// Up Button
			this.button = new Button();
			this.button.Location = new System.Drawing.Point(700, 150);
			this.button.Name = "Up_Button";
			this.button.Size = new System.Drawing.Size(100, 100);
			this.button.TabIndex = 0;
			this.button.Text = "Up";
			this.button.UseVisualStyleBackColor = true;
			this.button.Click += new System.EventHandler(this.Up_button_Click);
			this.Controls.Add(button);

			// Down Button
			this.button = new Button();
			this.button.Location = new System.Drawing.Point(700, 270);
			this.button.Name = "Down_Button";
			this.button.Size = new System.Drawing.Size(100, 100);
			this.button.TabIndex = 0;
			this.button.Text = "Down";
			this.button.UseVisualStyleBackColor = true;
			this.button.Click += new System.EventHandler(this.Down_button_Click);
			this.Controls.Add(button);

			// Left Button
			this.button = new Button();
			this.button.Location = new System.Drawing.Point(580, 270);
			this.button.Name = "Left_Button";
			this.button.Size = new System.Drawing.Size(100, 100);
			this.button.TabIndex = 0;
			this.button.Text = "Left";
			this.button.UseVisualStyleBackColor = true;
			this.button.Click += new System.EventHandler(this.Left_button_Click);
			this.Controls.Add(button);

			// Right Button
			this.button = new Button();
			this.button.Location = new System.Drawing.Point(820, 270);
			this.button.Name = "Left_Button";
			this.button.Size = new System.Drawing.Size(100, 100);
			this.button.TabIndex = 0;
			this.button.Text = "Right";
			this.button.UseVisualStyleBackColor = true;
			this.button.Click += new System.EventHandler(this.Right_button_Click);
			this.Controls.Add(button);

			//Undo Button
			this.button = new Button();
			this.button.Location = new System.Drawing.Point(870, 150);
			this.button.Name = "Undo_Button";
			this.button.Size = new System.Drawing.Size(50, 50);
			this.button.TabIndex = 0;
			this.button.Text = "Undo";
			this.button.UseVisualStyleBackColor = true;
			this.button.Click += new System.EventHandler(this.Undo_button_Click);
			this.Controls.Add(button);

		}
		bool isOverIndex(int x, int y)
		{
			int mapsizex = Map.GetLength(1);
			int mapsizey = Map.GetLength(0);
			if (x < 0 || x >= mapsizex)
				return true;
			if (y < 0 || y >= mapsizey)
				return true;
			return false;
		}
		void Swap(ref Point Now, int MoveX, int MoveY)
		{
			if (isOverIndex(MoveX, MoveY))
				return;

			int x1 = Now.X;
			int y1 = Now.Y;
			int x2 = MoveX;
			int y2 = MoveY;

			int temp = Map[y1, x1];
			Map[y1, x1] = Map[y2, x2];
			Map[y2, x2] = temp;

			Image tempimg = PictureArray[y1, x1].Image;
			PictureArray[y1, x1].Image = PictureArray[y2, x2].Image;
			PictureArray[y2, x2].Image = tempimg;
			Now.X = MoveX;
			Now.Y = MoveY;
		}
		void BlockMove(MoveTo select)
		{
			Debug.WriteLine(select);
			switch (select)
			{
				case MoveTo.UP:
					Swap(ref player, player.X, player.Y - 1);
					break;
				case MoveTo.DOWN:
					Swap(ref player, player.X, player.Y + 1);
					break;
				case MoveTo.LEFT:
					Swap(ref player, player.X - 1, player.Y);
					break;
				case MoveTo.RIGHT:
					Swap(ref player, player.X + 1, player.Y);
					break;
			}
		}
		void Setting()
		{
			// 왔던곳 다시 돌아가지 않게 제한.
			MoveTo select = MoveTo.DONOT;

			do
			{
				select = (MoveTo)rand.Next(4);
			} while (preMoveList[preMoveList.Count - 1] == select);

			if (player.X == 3 && player.Y == 3) // 우하 구석
			{
				if (preMoveList[preMoveList.Count - 1] == MoveTo.DOWN)
					select = MoveTo.LEFT;
				else if (preMoveList[preMoveList.Count - 1] == MoveTo.RIGHT)
					select = MoveTo.UP;
			}
			else if (player.X == 0 && player.Y == 3) // 좌하 구석
			{
				if (preMoveList[preMoveList.Count - 1] == MoveTo.DOWN)
					select = MoveTo.RIGHT;
				else if (preMoveList[preMoveList.Count - 1] == MoveTo.LEFT)
					select = MoveTo.UP;
			}
			else if (player.X == 3 && player.Y == 0) // 우상 구석
			{
				if (preMoveList[preMoveList.Count - 1] == MoveTo.UP)
					select = MoveTo.LEFT;
				else if (preMoveList[preMoveList.Count - 1] == MoveTo.RIGHT)
					select = MoveTo.DOWN;
			}
			else if (player.X == 0 && player.Y == 0) // 좌상 구석
			{
				if (preMoveList[preMoveList.Count - 1] == MoveTo.UP)
					select = MoveTo.RIGHT;
				else if (preMoveList[preMoveList.Count - 1] == MoveTo.LEFT)
					select = MoveTo.DOWN;
			}

			switch (select)
			{
				case MoveTo.UP:
					BlockMove(MoveTo.UP);
					break;
				case MoveTo.DOWN:
					BlockMove(MoveTo.DOWN);
					break;
				case MoveTo.LEFT:
					BlockMove(MoveTo.LEFT);
					break;
				case MoveTo.RIGHT:
					BlockMove(MoveTo.RIGHT);
					break;
			}
			if (preMoveList.Count == 5)
				preMoveList.RemoveAt(0);
			preMoveList.Add(select);
		}
		bool WinCheck()
		{
			if (player.X != 3 && player.Y != 3)
				return false;

			for(int y = 0; y < MapSizeY; y++)
			{
				for(int x = 0; x < MapSizeX; x++)
				{
					if (Map[y, x] != result[y, x])
						return false;
				}
			}
			return true;
		}
		MoveTo preMoveCheck(MoveTo p_move)
		{
			if (p_move == MoveTo.DOWN)
				return MoveTo.UP;
			else if (p_move == MoveTo.UP)
				return MoveTo.DOWN;
			else if (p_move == MoveTo.LEFT)
				return MoveTo.RIGHT;
			else if (p_move == MoveTo.RIGHT)
				return MoveTo.LEFT;
			else
				return MoveTo.DONOT;
		}
		private void Up_button_Click(object sender, EventArgs e)
		{
			Debug.WriteLine("Up Button Clicked");
			BlockMove(MoveTo.UP);
			if (preMoveList.Count == 5)
				preMoveList.RemoveAt(0);
			preMoveList.Add(MoveTo.UP);
			if (WinCheck())
			{
				MessageBox.Show("Congratulation!!", "You Win", MessageBoxButtons.OK);
				GameRun();
			}
		}
		private void Down_button_Click(object sender, EventArgs e)
		{
			Debug.WriteLine("Down Button Clicked");
			BlockMove(MoveTo.DOWN);
			if (preMoveList.Count == 5)
				preMoveList.RemoveAt(0);
			preMoveList.Add(MoveTo.DOWN);
			if (WinCheck())
			{
				MessageBox.Show("Congratulation!!", "You Win", MessageBoxButtons.OK);
				GameRun();
			}
		}
		private void Left_button_Click(object sender, EventArgs e)
		{
			Debug.WriteLine("Left Button Clicked");
			BlockMove(MoveTo.LEFT);
			if (preMoveList.Count == 5)
				preMoveList.RemoveAt(0);
			preMoveList.Add(MoveTo.LEFT);
			if (WinCheck())
			{
				MessageBox.Show("Congratulation!!", "You Win", MessageBoxButtons.OK);
				GameRun();
			}
		}
		private void Right_button_Click(object sender, EventArgs e)
		{
			Debug.WriteLine("Right Button Clicked");
			BlockMove(MoveTo.RIGHT);
			if (preMoveList.Count == 5)
				preMoveList.RemoveAt(0);
			preMoveList.Add(MoveTo.RIGHT);
			if (WinCheck())
			{
				MessageBox.Show("Congratulation!!", "You Win", MessageBoxButtons.OK);
				GameRun();
			}
		}
		private void Undo_button_Click(object sender, EventArgs e)
		{
			Debug.WriteLine("Redo Button Clicked");
			if (preMoveList.Count == 0 || preMoveList[0] == MoveTo.DONOT)
			{
				MessageBox.Show("Do not Redo", "Error", MessageBoxButtons.OK);
				return;
			}
			BlockMove(preMoveCheck(preMoveList[preMoveList.Count - 1]));
			
			preMoveList.RemoveAt(preMoveList.Count - 1);
		}
	}
}
