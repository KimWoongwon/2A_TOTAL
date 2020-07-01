using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AcidRain
{
    public partial class Form1 : Form
    {
        public class MoveLabel
        {
            public Label label { get; set; }
            public int MoveSpeed { get; }

            public MoveLabel(int pSpeed)
            {
                MoveSpeed = pSpeed;
            }
        }
        Timer m_Timer = null;
        Timer m_CreateLabelTimer = null;
        Timer m_GameLogicTimer = null;
        List<MoveLabel> LabelList = new List<MoveLabel>();
        Random rand = new Random();

        int m_Count = 0;
        public async void TimerCallFN()
        {
            while(true)
            {
                await Task.Delay(1000);
                m_Count++;
                Debug.WriteLine("가나다" + m_Count.ToString());
                int val = m_CreateLabelTimer.Interval - 300;
                if (val <= 500)
                {
                    val = 500;
                }
                m_CreateLabelTimer.Interval = val;
            }
        }
        
        public Form1()
        {
            InitializeComponent();

            TimerCallFN();

            m_Timer = new Timer();
            m_Timer.Interval = 20; // 50fps 0.02초 >> 1초에 50번
            m_Timer.Tick += UpdateEvent;
            m_Timer.Start();

            m_CreateLabelTimer = new Timer();
            m_CreateLabelTimer.Interval = 2000; // 50fps 0.02초 >> 1초에 50번
            m_CreateLabelTimer.Tick += CreateLabelEvent;
            m_CreateLabelTimer.Start();

            //m_GameLogicTimer = new Timer();
            //m_GameLogicTimer.Interval = 3000; // 50fps 0.02초 >> 1초에 50번
            //m_GameLogicTimer.Tick += GameLogicEvent;
            //m_GameLogicTimer.Start();
        }
        //public void GameLogicEvent(object sender, EventArgs e)
        //{
        //    int val = m_CreateLabelTimer.Interval - 300;
        //    if(val <= 500)
        //    {
        //        val = 500;
        //    }
        //    m_CreateLabelTimer.Stop();
        //    m_CreateLabelTimer.Interval = val;

        //    m_CreateLabelTimer.Start();
        //}
        public void CreateLabelEvent(object sender, EventArgs e)
        {
            MoveLabel temp = new MoveLabel(2);
            string templabel = RandomString.GetI.GetRandomString(E_LEVEL.Nomal);
            int widthPos = rand.Next(0, Size.Width - (templabel.Length * 15));
            
            temp.label = new Label();
            temp.label.AutoSize = true;
            temp.label.Location = new Point(widthPos, 0);
            temp.label.Name = templabel;
            temp.label.Size = new Size(38, 12);
            temp.label.TabIndex = 0;
            temp.label.Text = templabel;
            Controls.Add(temp.label);
            LabelList.Add(temp);
        }
        public void UpdateEvent(object sender, EventArgs e)
        {
            //label1.Location.Offset(0, 1); 이런 방법도 있다.
            if (LabelList.Count == 0)
                return;

            
            // 정방향 for문은 중간값이 사라졌을때 문제가 발생할수 있다. 
            // 처음에는 정방향 for문으로 했지만 역방향 for문이 좋은 선택인것 같다.
            for(int i = LabelList.Count - 1; i >= 0; i--)
            {
                Point pos = LabelList[i].label.Location;
                pos.Y += LabelList[i].MoveSpeed;
                LabelList[i].label.Location = pos;

                if (LabelList[i].label.Location.Y >= 360)
                {
                    RemoveLavel(LabelList[i]);
                    //LabelList[i].label.Dispose();   // null을 넣어주기 전에 Dispose가 필요하다.
                    //LabelList.RemoveAt(i);          // Controls에 남아있기 떄문이다.
                    //// label1.Location = new Point(randomindex, 0);
                }
            }

        }
        public void RemoveLavel(MoveLabel p_label)
        {
            p_label.label.Dispose();
            LabelList.Remove(p_label);
        }
        private void textBox1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                string temp = textBox1.Text;
                textBox1.Text = "";

                MoveLabel ll = LabelList.Find((obj) => { return obj.label.Text == temp; });
                if (ll != null)
                {
                    RemoveLavel(ll);
                    //ll.label.Dispose();
                    //LabelList.Remove(ll);
                }

                // < 2 >
                /*int removeidx = -1;
                for (int i = 0; i < LabelList.Count; i++)
                {
                    if (LabelList[i].label.Text.Contains(temp))
                    {
                        removeidx = i;
                        break;
                    }
                }
                if(removeidx >0)
                {
                    LabelList[removeidx].label.Dispose();
                    LabelList.RemoveAt(removeidx);
                }*/

                // < 1 >
                /*for (int i = LabelList.Count - 1; i >= 0; i--)
                {
                    if (LabelList[i].label.Text.Contains(temp))
                    {
                        LabelList[i].label.Dispose();
                        LabelList.RemoveAt(i);
                    }
                }*/
            }
        }
    }
}
