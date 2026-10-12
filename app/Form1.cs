using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Quantum_Controller
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            openPort();
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            if (quantum_port.IsOpen)
                quantum_port.Close();

            this.Close();
        }

        private void color1ind_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.Cancel)
                return;
            // установка цвета формы
            color1ind.BackColor = colorDialog1.Color;
        }

        private void color2ind_Click(object sender, EventArgs e)
        {
            if (colorDialog2.ShowDialog() == DialogResult.Cancel)
                return;
            // установка цвета формы
            color2ind.BackColor = colorDialog2.Color;
        }

        private void all_button_Click(object sender, EventArgs e)
        {
            sendCommand(9);
            //this.BackgroundImage = 
        }
        private void caseButton_Click(object sender, EventArgs e)
        {
            sendCommand(0);
        }
        private void fan1button_Click(object sender, EventArgs e)
        {
            sendCommand(1);
        }

        private void fan2button_Click(object sender, EventArgs e)
        {
            sendCommand(2);
        }

        private void fan3button_Click(object sender, EventArgs e)
        {
            sendCommand(3);
        }
        private void fanButton_Click(object sender, EventArgs e)
        {
            sendCommand(8);
        }

        private void openPort()
        {
            try
            {
                if (!quantum_port.IsOpen)
                    quantum_port.Open();

            }
            catch (Exception e)
            {
                //Console.WriteLine(e);
                quantum_port.Close();
            }
            //Console.WriteLine("Port is open " + quantum_port.IsOpen);

            if(quantum_port.IsOpen)
                quantum_port.Write("$r;");


            if (quantum_port.IsOpen)
                label2.ForeColor = Color.FromName("Green");
            else
                label2.ForeColor = Color.FromName("Red");
        }
        /*
            Один цвет
            Переливание
            Пульсирование
            Умное переливание
            Радуга
        */

        private String sendCommand(byte channel)
        {
            string[] vals = new string[4];

            String cmd = "$";

            String mode = comboBox1.Text;

            if (mode.Equals("Один цвет"))
            {
                cmd += "S";

                //Console.WriteLine("is {0:X}" + generateHex(colorDialog1.Color.ToArgb()));

                vals[0] = generateHex(colorDialog1.Color.ToArgb());
            }

            else if (mode.Equals("Переливание"))
            {

                cmd += "F";

                vals[0] = generateHex(colorDialog1.Color.ToArgb());
                vals[1] = generateHex(colorDialog2.Color.ToArgb());
                vals[2] = generateHex((int)(numericUpDown1.Value * 1000));
            }

            else if (mode.Equals("Пульсирование"))
            {

                cmd += "U";

                vals[0] = generateHex(colorDialog1.Color.ToArgb());
                //vals[1] = generateHex(colorDialog2.Color.ToArgb());
                vals[1] = generateHex((int)numericUpDown1.Value);// * 1000).ToString();

                //Console.WriteLine(numericUpDown1.Value);
                //Console.WriteLine((int)numericUpDown1.Value);
            }

            else if (mode.Equals("Умное переливание")) //Perlin
            {
                cmd += "P";

                vals[0] = generateHex((int)(colorDialog1.Color.GetHue() * 182.041666667));
                vals[1] = generateHex((int)(colorDialog2.Color.GetHue() * 182.041666667));
                vals[2] = generateHex((int)(numericUpDown1.Value * 10));
                vals[3] = "0X0000B4";
            }

            else if (mode.Equals("Радуга"))
            {

                cmd += "R";
                vals[0] = generateHex((int)numericUpDown1.Value);
            }

            else
                return null;

            cmd += channel;
            cmd += ":";

            for (int i = 0; i < 4 && vals[i] != null; i++)
            {
                cmd += vals[i];
                cmd += ":";
            }

            cmd = cmd.Substring(0, cmd.Length - 1);

            cmd += ";";

            Console.WriteLine("cmd : " + cmd);

            if (quantum_port.IsOpen)
                quantum_port.Write(cmd);
            else
            {
                openPort();

                MessageBox.Show("Не удалось установить соединение с контроллером.");
            }    

            return cmd;
        }




        private String generateHex(int inputVal)
        {
            int hexVal = inputVal & 0xffffff;

            String hex = hexVal.ToString("x");

            while (hex.Length != 6)
            {
                hex = "0" + hex;
            }

            hex = "0x" + hex;

            hex = hex.ToUpper();

            return hex.ToLower();
        }




        Point lastPoint;


        private void qc_text_MouseDown(object sender, MouseEventArgs e)
        {
            lastPoint = new Point(e.X, e.Y);
        }

        private void qc_text_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {

            if (quantum_port.IsOpen)
                quantum_port.Close();
            else
                openPort();

            if (quantum_port.IsOpen)
                label2.ForeColor = Color.FromName("Green");
            else
                label2.ForeColor = Color.FromName("Red");


        }
    }
}
