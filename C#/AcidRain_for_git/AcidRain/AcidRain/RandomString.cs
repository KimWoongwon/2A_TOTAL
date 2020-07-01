using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AcidRain
{
    public enum E_LEVEL
    {
        Basic,
        Nomal,

        Max
    }
    class RandomString
    {
        static RandomString m_Instance = null;
        public static RandomString GetI
        {
            get 
            { 
                if(m_Instance == null)
                {
                    m_Instance = new RandomString();
                }
                return m_Instance;
            }
        }
        

        string[,] m_Randstr = new string[(int)E_LEVEL.Max, 5] 
        {
            {
                "ㄱ", "ㄴ", "ㄷ", "ㄹ", "ㅁ"
            },
            {
                "가나다", "슭곰발", "동해", "백두산", "무궁화"
            }
        };

        Random rand = new Random();
        public string GetRandomString(E_LEVEL p_lv)
        {
            int randindex = rand.Next(0, m_Randstr.GetLength(1));
            return m_Randstr[(int)p_lv, randindex];
        }
    }
}
