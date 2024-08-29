using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Events_Delegation_By_Console_App
{
    /// <summary>
    /// Logger By Delegate
    /// </summary>
    public class Logger
    {
        public delegate void LogAction(string Message);

        private LogAction _LogAction;

        public Logger(LogAction Action) {
            this._LogAction = Action;
        }

        public void Log(string Message)
        {
            // _LogAction?.Invoke(Message);
            _LogAction(Message);
        }
    }

    public class LoggerImpl
    {
        public static void LogToScreen(string Message)
        {
            Console.WriteLine(Message);
        }

        public static void LogToFile(string Message)
        {
            string FileName = "Log.txt";

            using (StreamWriter Writer = new StreamWriter(FileName,true))
            {
                Writer.WriteLine(Message);
            }
        }
    }
}
