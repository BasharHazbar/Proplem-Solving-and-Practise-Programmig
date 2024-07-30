using System;



namespace calculator_project
{
    class clsCalculator
    {
        private float _Value;
        private string _OprationType;
        private float _OprationValue;
        private bool _IsZero(float value) 
        {  
            return value == 0; 
        }
        public clsCalculator() { 
            _Value = 0;
            _OprationType = " ";
            _OprationValue = 0;
        }

        public float Value
        {
            get
            {
                return _Value;
            }

            set
            {
                _Value = value;
            }

        }

        public void Clear()
        {
            _Value = 0;
            _OprationType = "Clear";
            _OprationValue = 0;
        }

        public void Add(float value)
        {
            _Value += value;
            _OprationType = "Add";
            _OprationValue = value;
        }

        public void Substruct(float value)
        {
            _Value -= value;
            _OprationType = "Substruct";
            _OprationValue = value;
        }

        public bool Divide(float value)
        {

            _OprationValue = value;

            bool succeed = false;

            if (_IsZero(value))
            {
                _Value /= 1;
            }
            else
            {
                succeed = true;
                _Value /= value;
            }
            _OprationType = "Divide";
            return succeed;
        }

        public void Multible(float value)
        {
            _Value *= value;
            _OprationType = "Multible";
            _OprationValue = value;
        }

        public void PrintResult()
        {
            Console.WriteLine("Result after {0} {1} is {2}",  _OprationType, _OprationValue, _Value);
        }

    }
    internal class Program
    {
        static void Main(string[] args)
        {
            clsCalculator clsCalculator1 = new clsCalculator();

            clsCalculator1.Clear();
            clsCalculator1.PrintResult();

            clsCalculator1.Add(100);
            clsCalculator1.PrintResult();

            clsCalculator1.Substruct(20);
            clsCalculator1.PrintResult();

            clsCalculator1.Divide(0);
            clsCalculator1.PrintResult();

            clsCalculator1.Divide(3);
            clsCalculator1.PrintResult();

            clsCalculator1.Multible(3);
            clsCalculator1.PrintResult();

            clsCalculator1.Clear();
            clsCalculator1.PrintResult();

        }
    }
}
