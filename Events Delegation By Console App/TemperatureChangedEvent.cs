using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Events_Delegation_By_Console_App
{
    /// <summary>
    /// Example One ==> TemperatureChangedEvent 
    /// </summary>
    public class TemperatureChangedEventArgs : EventArgs
    {

        public double OldTemperature { get; }
        public double NewTemperature { get; }
        public double Difference { get; }

        public TemperatureChangedEventArgs(double OldTemperature, double NewTemperature)
        {
            this.OldTemperature = OldTemperature;
            this.NewTemperature = NewTemperature;
            this.Difference = this.NewTemperature - this.OldTemperature; ;
        }

    }

    public class Thermostat
    {
        public EventHandler<TemperatureChangedEventArgs> TemperatureChanged;

        private double OldTemperature;
        private double CurrentTemperature;

        /*            public Thermostat(double NewTemperature)
                    {
                        if (NewTemperature != this.CurrentTemperature)
                        {
                            Console.WriteLine("Is Not Equal : " + (NewTemperature != this.CurrentTemperature));
                            this.OldTemperature = this.CurrentTemperature;
                            this.CurrentTemperature = NewTemperature;
                            //TemperatureChanged(this, new TemperatureChangedEventArgs(this.OldTemperature,this.CurrentTemperature));
                            OnTemperatureChanged(this.OldTemperature, this.CurrentTemperature);

                        }
                    }*/

        public void SetThermostat(double NewTemperature)
        {

            if (NewTemperature != this.CurrentTemperature)
            {
                this.OldTemperature = this.CurrentTemperature;
                this.CurrentTemperature = NewTemperature;
                //TemperatureChanged(this, new TemperatureChangedEventArgs(this.OldTemperature,this.CurrentTemperature));
                OnTemperatureChanged(this.OldTemperature, this.CurrentTemperature);

            }
        }

        private void OnTemperatureChanged(double OldTemperature, double CurrentTemperature)
        {
            OnTemperatureChanged(new TemperatureChangedEventArgs(OldTemperature, CurrentTemperature)); ;
        }
        protected virtual void OnTemperatureChanged(TemperatureChangedEventArgs e)
        {
            TemperatureChanged?.Invoke(this, e);
        }
    }

    public class Display
    {
        public void Subscribe(Thermostat Thermostat)
        {

            Thermostat.TemperatureChanged += HandleTemperatureChanged;
        }

        public void HandleTemperatureChanged(object sender, TemperatureChangedEventArgs e)
        {
            Console.WriteLine("Temperature Changed !!");
            Console.WriteLine($"Temperature Changed from {e.OldTemperature} C");
            Console.WriteLine($"Temperature Changed to {e.NewTemperature} C");
            Console.WriteLine($"Temperature Difference to {e.Difference} C");

            Console.WriteLine();
        }


    }
}
