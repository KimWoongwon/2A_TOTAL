namespace Sokoban
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
            this.DOWNBTN = new System.Windows.Forms.Button();
            this.LEFTBTN = new System.Windows.Forms.Button();
            this.RIGHTBTN = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // UPBTN
            // 
            this.UPBTN.Location = new System.Drawing.Point(611, 118);
            this.UPBTN.Name = "UPBTN";
            this.UPBTN.Size = new System.Drawing.Size(50, 50);
            this.UPBTN.TabIndex = 0;
            this.UPBTN.Text = "UP";
            this.UPBTN.UseVisualStyleBackColor = true;
            this.UPBTN.Click += new System.EventHandler(this.UPBTN_Click);
            // 
            // DOWNBTN
            // 
            this.DOWNBTN.Location = new System.Drawing.Point(611, 174);
            this.DOWNBTN.Name = "DOWNBTN";
            this.DOWNBTN.Size = new System.Drawing.Size(50, 50);
            this.DOWNBTN.TabIndex = 1;
            this.DOWNBTN.Text = "DOWN";
            this.DOWNBTN.UseVisualStyleBackColor = true;
            this.DOWNBTN.Click += new System.EventHandler(this.DOWNBTN_Click);
            // 
            // LEFTBTN
            // 
            this.LEFTBTN.Location = new System.Drawing.Point(555, 174);
            this.LEFTBTN.Name = "LEFTBTN";
            this.LEFTBTN.Size = new System.Drawing.Size(50, 50);
            this.LEFTBTN.TabIndex = 2;
            this.LEFTBTN.Text = "LEFT";
            this.LEFTBTN.UseVisualStyleBackColor = true;
            this.LEFTBTN.Click += new System.EventHandler(this.LEFTBTN_Click);
            // 
            // RIGHTBTN
            // 
            this.RIGHTBTN.Location = new System.Drawing.Point(667, 174);
            this.RIGHTBTN.Name = "RIGHTBTN";
            this.RIGHTBTN.Size = new System.Drawing.Size(50, 50);
            this.RIGHTBTN.TabIndex = 3;
            this.RIGHTBTN.Text = "RIGHT";
            this.RIGHTBTN.UseVisualStyleBackColor = true;
            this.RIGHTBTN.Click += new System.EventHandler(this.RIGHTBTN_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.RIGHTBTN);
            this.Controls.Add(this.LEFTBTN);
            this.Controls.Add(this.DOWNBTN);
            this.Controls.Add(this.UPBTN);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button UPBTN;
        private System.Windows.Forms.Button DOWNBTN;
        private System.Windows.Forms.Button LEFTBTN;
        private System.Windows.Forms.Button RIGHTBTN;
    }
}

