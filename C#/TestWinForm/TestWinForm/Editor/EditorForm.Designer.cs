namespace TestWinForm
{
    partial class EditorForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.WallBTN = new System.Windows.Forms.Button();
            this.GrassBTN = new System.Windows.Forms.Button();
            this.SelectIMG = new System.Windows.Forms.PictureBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.EditorSaveBTN = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.SelectIMG)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // WallBTN
            // 
            this.WallBTN.Image = global::TestWinForm.Properties.Resources.Wall_Brown;
            this.WallBTN.Location = new System.Drawing.Point(241, 354);
            this.WallBTN.Name = "WallBTN";
            this.WallBTN.Size = new System.Drawing.Size(61, 58);
            this.WallBTN.TabIndex = 0;
            this.WallBTN.Text = "벽";
            this.WallBTN.UseVisualStyleBackColor = true;
            this.WallBTN.Click += new System.EventHandler(this.WallBTN_Click);
            // 
            // GrassBTN
            // 
            this.GrassBTN.Image = global::TestWinForm.Properties.Resources.Ground_Grass;
            this.GrassBTN.Location = new System.Drawing.Point(174, 354);
            this.GrassBTN.Name = "GrassBTN";
            this.GrassBTN.Size = new System.Drawing.Size(61, 58);
            this.GrassBTN.TabIndex = 1;
            this.GrassBTN.Text = "잔디";
            this.GrassBTN.UseVisualStyleBackColor = true;
            this.GrassBTN.Click += new System.EventHandler(this.GrassBTN_Click);
            // 
            // SelectIMG
            // 
            this.SelectIMG.Location = new System.Drawing.Point(308, 354);
            this.SelectIMG.Name = "SelectIMG";
            this.SelectIMG.Size = new System.Drawing.Size(78, 76);
            this.SelectIMG.TabIndex = 2;
            this.SelectIMG.TabStop = false;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Enabled = false;
            this.pictureBox1.Image = global::TestWinForm.Properties.Resources.Character7;
            this.pictureBox1.Location = new System.Drawing.Point(518, 348);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(97, 82);
            this.pictureBox1.TabIndex = 3;
            this.pictureBox1.TabStop = false;
            // 
            // EditorSaveBTN
            // 
            this.EditorSaveBTN.Location = new System.Drawing.Point(676, 290);
            this.EditorSaveBTN.Name = "EditorSaveBTN";
            this.EditorSaveBTN.Size = new System.Drawing.Size(61, 58);
            this.EditorSaveBTN.TabIndex = 4;
            this.EditorSaveBTN.Text = "적용";
            this.EditorSaveBTN.UseVisualStyleBackColor = true;
            this.EditorSaveBTN.Click += new System.EventHandler(this.EditorSaveBTN_Click);
            // 
            // EditorForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.EditorSaveBTN);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.SelectIMG);
            this.Controls.Add(this.GrassBTN);
            this.Controls.Add(this.WallBTN);
            this.Name = "EditorForm";
            this.Text = "EditorForm";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.EditorForm_Paint);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.EditorForm_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.EditorForm_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.EditorForm_MouseUp);
            ((System.ComponentModel.ISupportInitialize)(this.SelectIMG)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button WallBTN;
        private System.Windows.Forms.Button GrassBTN;
        private System.Windows.Forms.PictureBox SelectIMG;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button EditorSaveBTN;
    }
}