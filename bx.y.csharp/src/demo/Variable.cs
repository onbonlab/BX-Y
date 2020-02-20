using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Ysdk_CSharp
{
    public class Variable
    {
        public static List<LedYNetSdk.BroadCast2> BroadCastlist = new List<LedYNetSdk.BroadCast2>();
        public static int p_index;

        public static byte[] p_ip = Encoding.ASCII.GetBytes("127.0.0.1");//服务器IP
        public static ushort p_port = 80;
        public static string p_str = "guest";

        public static int p_width;
        public static int p_height;
        public static int p_screen_type;
        public static int p_brigtness_mode;
        public static int p_brigtness;

        public static int num_program=0;
        public static string ToHexColor(Color color)
        {
            if (color.IsEmpty)
                return "0xff000000";
            string hexString = "0x" + color.A.ToString("X2");
            hexString += color.R.ToString("X2");
            hexString += color.G.ToString("X2");
            hexString += color.B.ToString("X2");
            return hexString;
        }
    }
}
