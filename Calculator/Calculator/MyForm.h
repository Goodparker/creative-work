#pragma once
namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Функция возведения в степень
	double power(double x, int y) {
		return System::Math::Pow(x, y);
	}
	//Функция для вычисления косинуса
	double cosinus(double x) {
		return System::Math::Cos(x);
	}
	//Функция для вычисления арккосинуса
	double acosinus(double x) {
		return System::Math::Acos(x);
	}
	//Функция для вычисления синуса
	double sinus(double x) {
		return System::Math::Sin(x);
	}
	//Функция для вычисления арксинуса
	double asinus(double x) {
		return System::Math::Asin(x);
	}
	//Функция для вычисления тангенсов
	double tangens(double x) {
		return System::Math::Tan(x);
	}
	//Функция для вычисления арктангенсов
	double atangens(double x) {
		return System::Math::Atan(x);
	}
	//Функция для вычисления логарифма
	float logar(double a, double b) {
		return (System::Math::Log(b) / System::Math::Log(a));
	}
	// Функция перевода в тип Int
	int todouble(System::String^ str, int y) {
		switch (str[y])
		{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default:
			break;
		}
	}
	//Функция проверки, является ли следующий знак числом
	bool nextch(System::String^ str,int tek) {
		if (str[tek+1] >= '0' && str[tek + 1] <= '9') {
			return true;
		}
		else {
			return false;
		}
	}
	//Функция проверки, является ли предыдущий знак числом
	bool prevch(System::String^ str, int tek) {
		if (str[tek - 1] >= '0' && str[tek - 1] <= '9') {
			return true;
		}
		else {
			return false;
		}
	}
	// Функция проверки на pi, x и e
	bool per(System::String^ str, int tek) {
		if (str[tek] == 'x' || str[tek] == 'i' || str[tek] == 'e') {
			return true;
		}
		else {
			return false;
		}
	}
	/// <summary>
	/// Сводка для MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;




















	private: System::Windows::Forms::Label^ label13;















	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label12;



	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Button^ button2;







	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(21, 169);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(201, 41);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(17, 11);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(215, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Введите уравнение:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(17, 68);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(241, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Введите промежуток:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(32, 96);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(37, 25);
			this->label3->TabIndex = 6;
			this->label3->Text = L"от";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(73, 96);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(69, 22);
			this->textBox2->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(201, 98);
			this->textBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(69, 22);
			this->textBox3->TabIndex = 8;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(152, 96);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 25);
			this->label4->TabIndex = 9;
			this->label4->Text = L"до";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(157, 219);
			this->textBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(139, 22);
			this->textBox4->TabIndex = 10;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Location = System::Drawing::Point(17, 217);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(127, 25);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Результат:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label13->Location = System::Drawing::Point(485, 39);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(43, 25);
			this->label13->TabIndex = 33;
			this->label13->Text = L"= 0";
			this->label13->Click += gcnew System::EventHandler(this, &MyForm::label13_Click_1);
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(384, 132);
			this->textBox10->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(69, 22);
			this->textBox10->TabIndex = 49;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label12->Location = System::Drawing::Point(16, 132);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(335, 25);
			this->label12->TabIndex = 50;
			this->label12->Text = L"Введите точность вычислений:";
			this->label12->Click += gcnew System::EventHandler(this, &MyForm::label12_Click);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(23, 39);
			this->textBox11->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(453, 22);
			this->textBox11->TabIndex = 54;
			this->textBox11->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox11_TextChanged);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(372, 228);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(172, 39);
			this->button2->TabIndex = 55;
			this->button2->Text = L"Очистить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(547, 271);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->Text = L"Калькулятор уравнений";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Protect()) {
			System::String^ s;
			bool fl;
			double a, b, c, e;
			int ez, num;
			double Result, prom;
			double mx[10];
			for (int i = 0; i < 10; i++) {
				mx[i] = 0;
			}
			double co[10];
			for (int i = 0; i < 10; i++) {
				co[i] = 0;
			}
			double nums[100];
			for (int i = 0; i < 100; i++) {
				nums[i] = 0;
			}
			prom = 0;
			Result = 0;
			a = 0;
			b = 0;
			e = 0;
			c = 0;
			ez = 0;
			// Проверка коректности ввода точности вычислений
			if ((textBox10->Text->Length == 0)) {
				MessageBox::Show("Введите точность вычислений!");
			}
			else {
				e = System::Convert::ToDouble(textBox10->Text);
				num = textBox10->Text->Length;
				ez = num - 2;
			}
			//Проверка корректонсти ввода промежутка 
			if ((textBox2->Text->Length == 0) || (textBox3->Text->Length == 0)) {
				MessageBox::Show("Введите промежуток!");
				fl = false;
			}
			else {
				a = System::Convert::ToDouble(textBox2->Text);
				b = System::Convert::ToDouble(textBox3->Text);
				fl = true;
			}
				s = "     " + textBox11->Text + "     ";
				for (int i = 5; i < s->Length - 5; i++) {
					if (s[i] <= '9' && s[i] >= '0') {
						int r = 0;
						// Числа
						if (!nextch(s, i)) {
							if (prevch(s, i) && prevch(s, i - 1)) {
								if (s[i - 3] == '-') {
									nums[i] = -(todouble(s, i - 2) * 100 + todouble(s, i - 1) * 10 + todouble(s, i));
								}
								else {
									nums[i] = todouble(s, i - 2) * 100 + todouble(s, i - 1) * 10 + todouble(s, i);
								}
							}
							if (!prevch(s, i - 1) && prevch(s, i)) {
								if (s[i - 2] == '-') {
									nums[i] = -(todouble(s, i - 1) * 10 + todouble(s, i));
								}
								else {
									nums[i] = todouble(s, i - 1) * 10 + todouble(s, i);
								}
							}
							if (!prevch(s, i)) {
								if (s[i - 1] == '-') {
									nums[i] = -todouble(s, i);
								}
								else {
									nums[i] = todouble(s, i);
								}
							}
						}
					}
					// Степень у x
					if (s[i] == 'x') {
						if (s[i + 1] == '^' && s[i + 2] == '(' && s[i + 4] == ')') {
							switch (s[i + 3])
							{
							case '0':
								mx[0] = 0;
								if (s[i - 1] == '*') {
									int j = 1;
									bool ch = false;
									while (!ch) {
										if (nums[i - j] != 0) {
											ch = true;
										}
										else {
											j++;
										}
									}
									co[0] = nums[i - j];
								}
								break;
							case '1':
								mx[1] = 1;
								if (s[i - 1] == '*') {
									int j = 1;
									bool ch = false;
									while (!ch) {
										if (nums[i - j] != 0) {
											ch = true;
										}
										else {
											j++;
										}
									}
									co[1] = nums[i - j];
								}
								break;
							case '2':
								mx[2] = 2;
								if (s[i - 1] == '*') {
									int j = 1;
									bool ch = false;
									while (!ch) {
										if (nums[i - j] != 0) {
											ch = true;
										}
										else {
											j++;
										}
									}
									co[2] = nums[i - j];
								}
								break;
							case '3':
								mx[3] = 3;
								if (s[i - 1] == '*') {
									int j = 1;
									bool ch = false;
									while (!ch) {
										if (nums[i - j] != 0) {
											ch = true;
										}
										else {
											j++;
										}
									}
									co[3] = nums[i - j];
									nums[i - j] = 0;
								}
								break;
							case '4':
								mx[4] = 4;
								if (s[i - 1] == '*') {
									int j = 1;
									bool ch = false;
									while (!ch) {
										if (nums[i - j] != 0) {
											ch = true;
										}
										else {
											j++;
										}
									}
									co[4] = nums[i - j];
									nums[i - j] = 0;
								}
								break;
							case '5':
								mx[5] = 5;
								if (s[i - 1] == '*') {
									int j = 1;
									bool ch = false;
									while (!ch) {
										if (nums[i - j] != 0) {
											ch = true;
										}
										else {
											j++;
										}
									}
									co[5] = nums[i - j];
									nums[i - j] = 0;
								}
								break;
							case '6':
								mx[6] = 6;
								if (s[i - 1] == '*') {
									int j = 1;
									bool ch = false;
									while (!ch) {
										if (nums[i - j] != 0) {
											ch = true;
										}
										else {
											j++;
										}
									}
									co[6] = nums[i - j];
									nums[i - j] = 0;
								}
								break;
							case '7':
								mx[7] = 7;
								if (s[i - 1] == '*') {
									int j = 1;
									bool ch = false;
									while (!ch) {
										if (nums[i - j] != 0) {
											ch = true;
										}
										else {
											j++;
										}
									}
									co[7] = nums[i - j];
									nums[i - j] = 0;
								}
								break;
							case '8':
								mx[8] = 8;
								if (s[i - 1] == '*') {
									int j = 1;
									bool ch = false;
									while (!ch) {
										if (nums[i - j] != 0) {
											ch = true;
										}
										else {
											j++;
										}
									}
									co[8] = nums[i - j];
									nums[i - j] = 0;
								}
								break;
							case '9':
								mx[9] = 9;
								if (s[i - 1] == '*') {
									int j = 1;
									bool ch = false;
									while (!ch) {
										if (nums[i - j] != 0) {
											ch = true;
										}
										else {
											j++;
										}
									}
									co[9] = nums[i - j];
									nums[i - j] = 0;
								}
								break;
							default:
								break;
							}
						}
					}
				}
				// Вычисление результата методом половинного деления
				Result = 0;
				while ((b - a) > e) {
					c = (a + b) / 2;
					if (((co[9] * power(a, mx[9]) + co[8] * power(a, mx[8]) + co[7] * power(a, mx[7]) + co[6] * power(a, mx[6]) + co[5] * power(a, mx[5]) + co[4] * power(a, mx[4]) + co[3] * power(a, mx[3]) + co[2] * power(a, mx[2]) + co[1] * power(a, mx[1]) + co[0]) * (co[9] * power(c, mx[9]) + co[8] * power(c, mx[8]) + co[7] * power(c, mx[7]) + co[6] * power(c, mx[6]) + co[5] * power(c, mx[5]) + co[4] * power(c, mx[4]) + co[3] * power(c, mx[3]) + co[2] * power(c, mx[2]) + co[1] * power(c, mx[1]) + co[0])) > 0) {
						a = c;
					}
					else {
						b = c;
					}
				}
				if (((System::Convert::ToInt32(textBox2->Text) + System::Convert::ToInt32(textBox3->Text)) % 2) == 0) {
					Result = System::Math::Round(c, ez) + e;
				}
				else {
					Result = System::Math::Round(c, ez);
				}
				textBox4->Text = System::Convert::ToString(Result);
			}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox11->Text = "";
	textBox10->Text = "";
	textBox2->Text = "";
	textBox3->Text = "";
	textBox4->Text = "";
}
		// Функция защиты от неверного ввода
		   bool Protect() {
			for (int i = 0; i < textBox2->Text->Length; i++) {
				if ((textBox2->Text[i] >= '0') && (textBox2->Text[i] <= '9') || (textBox2->Text[i] == ',') || (textBox2->Text[i] == '-')) {}
				else { MessageBox::Show("Неверный ввод!\nПроверьте, правильно ли указано начало интервала"); return false; }
			}
			for (int i = 0; i < textBox3->Text->Length; i++) {
				if ((textBox3->Text[i] >= '0') && (textBox3->Text[i] <= '9') || (textBox3->Text[i] == ',') || (textBox3->Text[i] == '-')) {}
				else { MessageBox::Show("Неверный ввод!\nПроверьте, правильно ли указан конец интервала"); return false; }
			}
			for (int i = 0; i < textBox10->Text->Length; i++) {
				if ((textBox10->Text[i] >= '0') && (textBox10->Text[i] <= '9') || (textBox10->Text[i] == ',') || (textBox10->Text[i] == '-')) {}
				else { MessageBox::Show("Неверный ввод!\nПроверьте, правильно ли указана точность вычислений"); return false; }
			}
			return true;
		}

	private: System::Void listBox1_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e) {
	}
		   // Изменение окна, в зависимости от вида уравнения
	
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label13_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label13_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox5_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox6_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox11_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}