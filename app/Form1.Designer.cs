
namespace Quantum_Controller
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.panel1 = new System.Windows.Forms.Panel();
            this.closeButton = new System.Windows.Forms.Label();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.speedLable = new System.Windows.Forms.Label();
            this.caseButton = new System.Windows.Forms.Button();
            this.fan2button = new System.Windows.Forms.Button();
            this.fan3button = new System.Windows.Forms.Button();
            this.fan1button = new System.Windows.Forms.Button();
            this.fanButton = new System.Windows.Forms.Button();
            this.all_button = new System.Windows.Forms.Button();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.mode_text = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.color1text = new System.Windows.Forms.Label();
            this.color2ind = new System.Windows.Forms.Panel();
            this.color1ind = new System.Windows.Forms.Panel();
            this.qc_text = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.quantum_port = new System.IO.Ports.SerialPort(this.components);
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.colorDialog2 = new System.Windows.Forms.ColorDialog();
            this.label2 = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.Black;
            this.panel1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("panel1.BackgroundImage")));
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.closeButton);
            this.panel1.Controls.Add(this.numericUpDown1);
            this.panel1.Controls.Add(this.speedLable);
            this.panel1.Controls.Add(this.caseButton);
            this.panel1.Controls.Add(this.fan2button);
            this.panel1.Controls.Add(this.fan3button);
            this.panel1.Controls.Add(this.fan1button);
            this.panel1.Controls.Add(this.fanButton);
            this.panel1.Controls.Add(this.all_button);
            this.panel1.Controls.Add(this.comboBox1);
            this.panel1.Controls.Add(this.mode_text);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.color1text);
            this.panel1.Controls.Add(this.color2ind);
            this.panel1.Controls.Add(this.color1ind);
            this.panel1.Controls.Add(this.qc_text);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Cursor = System.Windows.Forms.Cursors.Default;
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Font = new System.Drawing.Font("Corbel", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(400, 400);
            this.panel1.TabIndex = 0;
            // 
            // closeButton
            // 
            this.closeButton.AutoSize = true;
            this.closeButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.closeButton.Font = new System.Drawing.Font("Lucida Console", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.closeButton.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(91)))), ((int)(((byte)(150)))));
            this.closeButton.Location = new System.Drawing.Point(377, 0);
            this.closeButton.Name = "closeButton";
            this.closeButton.Size = new System.Drawing.Size(23, 21);
            this.closeButton.TabIndex = 2;
            this.closeButton.Text = "x";
            this.closeButton.Click += new System.EventHandler(this.closeButton_Click);
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.BackColor = System.Drawing.Color.Black;
            this.numericUpDown1.Font = new System.Drawing.Font("Corbel", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.numericUpDown1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.numericUpDown1.Location = new System.Drawing.Point(315, 147);
            this.numericUpDown1.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDown1.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(48, 27);
            this.numericUpDown1.TabIndex = 20;
            this.numericUpDown1.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // speedLable
            // 
            this.speedLable.AutoSize = true;
            this.speedLable.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.speedLable.ForeColor = System.Drawing.Color.Teal;
            this.speedLable.Location = new System.Drawing.Point(228, 148);
            this.speedLable.Name = "speedLable";
            this.speedLable.Size = new System.Drawing.Size(81, 20);
            this.speedLable.TabIndex = 19;
            this.speedLable.Text = "Скорость";
            // 
            // caseButton
            // 
            this.caseButton.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.caseButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.caseButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(32)))), ((int)(((byte)(32)))));
            this.caseButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.caseButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.caseButton.ForeColor = System.Drawing.Color.Teal;
            this.caseButton.Location = new System.Drawing.Point(30, 300);
            this.caseButton.Name = "caseButton";
            this.caseButton.Size = new System.Drawing.Size(102, 30);
            this.caseButton.TabIndex = 18;
            this.caseButton.Text = "Корпус";
            this.caseButton.UseMnemonic = false;
            this.caseButton.UseVisualStyleBackColor = false;
            this.caseButton.Click += new System.EventHandler(this.caseButton_Click);
            // 
            // fan2button
            // 
            this.fan2button.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.fan2button.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.fan2button.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(32)))), ((int)(((byte)(32)))));
            this.fan2button.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.fan2button.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.fan2button.ForeColor = System.Drawing.Color.Teal;
            this.fan2button.Location = new System.Drawing.Point(286, 360);
            this.fan2button.Name = "fan2button";
            this.fan2button.Size = new System.Drawing.Size(30, 30);
            this.fan2button.TabIndex = 17;
            this.fan2button.Text = "2";
            this.fan2button.UseMnemonic = false;
            this.fan2button.UseVisualStyleBackColor = false;
            this.fan2button.Click += new System.EventHandler(this.fan2button_Click);
            // 
            // fan3button
            // 
            this.fan3button.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.fan3button.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.fan3button.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(32)))), ((int)(((byte)(32)))));
            this.fan3button.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.fan3button.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.fan3button.ForeColor = System.Drawing.Color.Teal;
            this.fan3button.Location = new System.Drawing.Point(322, 360);
            this.fan3button.Name = "fan3button";
            this.fan3button.Size = new System.Drawing.Size(30, 30);
            this.fan3button.TabIndex = 16;
            this.fan3button.Text = "3";
            this.fan3button.UseMnemonic = false;
            this.fan3button.UseVisualStyleBackColor = false;
            this.fan3button.Click += new System.EventHandler(this.fan3button_Click);
            // 
            // fan1button
            // 
            this.fan1button.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.fan1button.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.fan1button.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(32)))), ((int)(((byte)(32)))));
            this.fan1button.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.fan1button.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.fan1button.ForeColor = System.Drawing.Color.Teal;
            this.fan1button.Location = new System.Drawing.Point(250, 360);
            this.fan1button.Name = "fan1button";
            this.fan1button.Size = new System.Drawing.Size(30, 30);
            this.fan1button.TabIndex = 15;
            this.fan1button.Text = "1";
            this.fan1button.UseMnemonic = false;
            this.fan1button.UseVisualStyleBackColor = false;
            this.fan1button.Click += new System.EventHandler(this.fan1button_Click);
            // 
            // fanButton
            // 
            this.fanButton.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.fanButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.fanButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(32)))), ((int)(((byte)(32)))));
            this.fanButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.fanButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.fanButton.ForeColor = System.Drawing.Color.Teal;
            this.fanButton.Location = new System.Drawing.Point(250, 300);
            this.fanButton.Name = "fanButton";
            this.fanButton.Size = new System.Drawing.Size(102, 30);
            this.fanButton.TabIndex = 14;
            this.fanButton.Text = "Кулеры";
            this.fanButton.UseMnemonic = false;
            this.fanButton.UseVisualStyleBackColor = false;
            this.fanButton.Click += new System.EventHandler(this.fanButton_Click);
            // 
            // all_button
            // 
            this.all_button.FlatAppearance.BorderColor = System.Drawing.Color.White;
            this.all_button.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.all_button.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(32)))), ((int)(((byte)(32)))));
            this.all_button.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.all_button.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.all_button.ForeColor = System.Drawing.Color.Teal;
            this.all_button.Location = new System.Drawing.Point(164, 240);
            this.all_button.Name = "all_button";
            this.all_button.Size = new System.Drawing.Size(70, 30);
            this.all_button.TabIndex = 13;
            this.all_button.Text = "Все";
            this.all_button.UseMnemonic = false;
            this.all_button.UseVisualStyleBackColor = false;
            this.all_button.Click += new System.EventHandler(this.all_button_Click);
            // 
            // comboBox1
            // 
            this.comboBox1.BackColor = System.Drawing.Color.Black;
            this.comboBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.comboBox1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.comboBox1.Items.AddRange(new object[] {
            "Один цвет",
            "Пульсирование",
            "Переливание",
            "Умное переливание",
            "Радуга"});
            this.comboBox1.Location = new System.Drawing.Point(96, 46);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(213, 28);
            this.comboBox1.TabIndex = 11;
            // 
            // mode_text
            // 
            this.mode_text.AutoSize = true;
            this.mode_text.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.mode_text.ForeColor = System.Drawing.Color.Teal;
            this.mode_text.Location = new System.Drawing.Point(14, 49);
            this.mode_text.Name = "mode_text";
            this.mode_text.Size = new System.Drawing.Size(59, 20);
            this.mode_text.TabIndex = 10;
            this.mode_text.Text = "Режим";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.ForeColor = System.Drawing.Color.Teal;
            this.label1.Location = new System.Drawing.Point(14, 148);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(61, 20);
            this.label1.TabIndex = 6;
            this.label1.Text = "Цвет 2";
            // 
            // color1text
            // 
            this.color1text.AutoSize = true;
            this.color1text.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.color1text.ForeColor = System.Drawing.Color.Teal;
            this.color1text.Location = new System.Drawing.Point(14, 110);
            this.color1text.Name = "color1text";
            this.color1text.Size = new System.Drawing.Size(61, 20);
            this.color1text.TabIndex = 5;
            this.color1text.Text = "Цвет 1";
            // 
            // color2ind
            // 
            this.color2ind.BackColor = System.Drawing.Color.Gray;
            this.color2ind.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.color2ind.Cursor = System.Windows.Forms.Cursors.Hand;
            this.color2ind.Location = new System.Drawing.Point(81, 148);
            this.color2ind.Name = "color2ind";
            this.color2ind.Size = new System.Drawing.Size(20, 20);
            this.color2ind.TabIndex = 4;
            this.color2ind.Click += new System.EventHandler(this.color2ind_Click);
            // 
            // color1ind
            // 
            this.color1ind.BackColor = System.Drawing.Color.Gray;
            this.color1ind.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.color1ind.Cursor = System.Windows.Forms.Cursors.Hand;
            this.color1ind.Location = new System.Drawing.Point(81, 110);
            this.color1ind.Name = "color1ind";
            this.color1ind.Size = new System.Drawing.Size(20, 20);
            this.color1ind.TabIndex = 3;
            this.color1ind.Click += new System.EventHandler(this.color1ind_Click);
            // 
            // qc_text
            // 
            this.qc_text.Dock = System.Windows.Forms.DockStyle.Top;
            this.qc_text.ForeColor = System.Drawing.Color.Aqua;
            this.qc_text.Image = ((System.Drawing.Image)(resources.GetObject("qc_text.Image")));
            this.qc_text.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.qc_text.Location = new System.Drawing.Point(0, 0);
            this.qc_text.Name = "qc_text";
            this.qc_text.Size = new System.Drawing.Size(400, 33);
            this.qc_text.TabIndex = 7;
            this.qc_text.Text = "Quantum Controller";
            this.qc_text.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.qc_text.MouseDown += new System.Windows.Forms.MouseEventHandler(this.qc_text_MouseDown);
            this.qc_text.MouseMove += new System.Windows.Forms.MouseEventHandler(this.qc_text_MouseMove);
            // 
            // label3
            // 
            this.label3.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.ForeColor = System.Drawing.Color.Teal;
            this.label3.Image = ((System.Drawing.Image)(resources.GetObject("label3.Image")));
            this.label3.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.label3.Location = new System.Drawing.Point(0, 196);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(400, 204);
            this.label3.TabIndex = 12;
            this.label3.Text = "Применить на";
            this.label3.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // quantum_port
            // 
            this.quantum_port.BaudRate = 4800;
            this.quantum_port.PortName = "COM3";
            // 
            // colorDialog1
            // 
            this.colorDialog1.AnyColor = true;
            this.colorDialog1.FullOpen = true;
            // 
            // colorDialog2
            // 
            this.colorDialog2.AnyColor = true;
            this.colorDialog2.FullOpen = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.label2.Font = new System.Drawing.Font("Lucida Console", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(91)))), ((int)(((byte)(150)))));
            this.label2.Location = new System.Drawing.Point(377, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(23, 21);
            this.label2.TabIndex = 21;
            this.label2.Text = "o";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoValidate = System.Windows.Forms.AutoValidate.EnablePreventFocusChange;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.CausesValidation = false;
            this.ClientSize = new System.Drawing.Size(400, 400);
            this.ControlBox = false;
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Quantum Controller";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label closeButton;
        private System.IO.Ports.SerialPort quantum_port;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.Label color1text;
        private System.Windows.Forms.Panel color2ind;
        private System.Windows.Forms.Panel color1ind;
        private System.Windows.Forms.ColorDialog colorDialog2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label qc_text;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Label mode_text;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button all_button;
        private System.Windows.Forms.Button fan2button;
        private System.Windows.Forms.Button fan3button;
        private System.Windows.Forms.Button fan1button;
        private System.Windows.Forms.Button fanButton;
        private System.Windows.Forms.Button caseButton;
        private System.Windows.Forms.Label speedLable;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.Label label2;
    }
}

