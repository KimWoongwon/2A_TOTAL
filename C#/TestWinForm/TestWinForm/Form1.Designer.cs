namespace TestWinForm
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.UPBTN = new System.Windows.Forms.Button();
            this.RightBTN = new System.Windows.Forms.Button();
            this.DownBTN = new System.Windows.Forms.Button();
            this.LeftBTN = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.ResetBTN = new System.Windows.Forms.Button();
            this.EditorBTN = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.SuspendLayout();
            // 
            // UPBTN
            // 
            this.UPBTN.Location = new System.Drawing.Point(669, 253);
            this.UPBTN.Name = "UPBTN";
            this.UPBTN.Size = new System.Drawing.Size(50, 50);
            this.UPBTN.TabIndex = 3;
            this.UPBTN.Text = "UP";
            this.UPBTN.UseVisualStyleBackColor = true;
            this.UPBTN.Click += new System.EventHandler(this.UPBTN_Click);
            // 
            // RightBTN
            // 
            this.RightBTN.Location = new System.Drawing.Point(725, 291);
            this.RightBTN.Name = "RightBTN";
            this.RightBTN.Size = new System.Drawing.Size(50, 50);
            this.RightBTN.TabIndex = 4;
            this.RightBTN.Text = "Right";
            this.RightBTN.UseVisualStyleBackColor = true;
            this.RightBTN.Click += new System.EventHandler(this.RightBTN_Click);
            // 
            // DownBTN
            // 
            this.DownBTN.Location = new System.Drawing.Point(669, 333);
            this.DownBTN.Name = "DownBTN";
            this.DownBTN.Size = new System.Drawing.Size(50, 50);
            this.DownBTN.TabIndex = 5;
            this.DownBTN.Text = "Down";
            this.DownBTN.UseVisualStyleBackColor = true;
            this.DownBTN.Click += new System.EventHandler(this.DownBTN_Click);
            // 
            // LeftBTN
            // 
            this.LeftBTN.Location = new System.Drawing.Point(613, 291);
            this.LeftBTN.Name = "LeftBTN";
            this.LeftBTN.Size = new System.Drawing.Size(50, 50);
            this.LeftBTN.TabIndex = 6;
            this.LeftBTN.Text = "Left";
            this.LeftBTN.UseVisualStyleBackColor = true;
            this.LeftBTN.Click += new System.EventHandler(this.LeftBTN_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::TestWinForm.Properties.Resources.Character4;
            this.pictureBox1.Location = new System.Drawing.Point(520, 382);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(45, 69);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // pictureBox3
            // 
            this.pictureBox3.Image = global::TestWinForm.Properties.Resources.Wall_Brown;
            this.pictureBox3.Location = new System.Drawing.Point(538, 382);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(69, 82);
            this.pictureBox3.TabIndex = 2;
            this.pictureBox3.TabStop = false;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Image = global::TestWinForm.Properties.Resources.Wall_Brown;
            this.pictureBox2.Location = new System.Drawing.Point(472, 382);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(69, 82);
            this.pictureBox2.TabIndex = 1;
            this.pictureBox2.TabStop = false;
            // 
            // ResetBTN
            // 
            this.ResetBTN.Location = new System.Drawing.Point(725, 388);
            this.ResetBTN.Name = "ResetBTN";
            this.ResetBTN.Size = new System.Drawing.Size(50, 50);
            this.ResetBTN.TabIndex = 7;
            this.ResetBTN.Text = "초기화";
            this.ResetBTN.UseVisualStyleBackColor = true;
            this.ResetBTN.Click += new System.EventHandler(this.ResetBTN_Click);
            // 
            // EditorBTN
            // 
            this.EditorBTN.Location = new System.Drawing.Point(264, 382);
            this.EditorBTN.Name = "EditorBTN";
            this.EditorBTN.Size = new System.Drawing.Size(107, 50);
            this.EditorBTN.TabIndex = 8;
            this.EditorBTN.Text = "에디터열기";
            this.EditorBTN.UseVisualStyleBackColor = true;
            this.EditorBTN.Click += new System.EventHandler(this.EditorBTN_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.EditorBTN);
            this.Controls.Add(this.ResetBTN);
            this.Controls.Add(this.LeftBTN);
            this.Controls.Add(this.DownBTN);
            this.Controls.Add(this.RightBTN);
            this.Controls.Add(this.UPBTN);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.pictureBox3);
            this.Controls.Add(this.pictureBox2);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.PictureBox pictureBox3;
        private System.Windows.Forms.Button UPBTN;
        private System.Windows.Forms.Button RightBTN;
        private System.Windows.Forms.Button DownBTN;
        private System.Windows.Forms.Button LeftBTN;
        private System.Windows.Forms.Button ResetBTN;
        private System.Windows.Forms.Button EditorBTN;
    }
}

