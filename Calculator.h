#pragma once
#include "cFraction.h"
#include <vector>
#include <algorithm>
#include <functional>

bool t_numerator1_ready = false;
bool  t_denumerator1_ready = false;
bool  t_numerator2_ready = false;
bool  t_denumerator2_ready = false;
const int NOVALUE = -2147483648;

namespace calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Calculator
	/// </summary>
	public ref class Calculator : public System::Windows::Forms::Form
	{
		


	public:
		Calculator(void)
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
		~Calculator()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ t_numerator1;
	private: System::Windows::Forms::TextBox^ t_denumerator1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ t_denumerator2;
	private: System::Windows::Forms::TextBox^ t_numerator2;
	private: System::Windows::Forms::Button^ b_calculate;
	private: System::Windows::Forms::Label^ l_numerator;
	private: System::Windows::Forms::Label^ l_denumerator;
	private: System::Windows::Forms::ComboBox^ cb_sign1;
	private: System::Windows::Forms::ComboBox^ cb_sign2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ cb_type2;
	private: System::Windows::Forms::ComboBox^ cb_type1;
	private: System::Windows::Forms::ComboBox^ cb_type3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ l_error;





	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Calculator::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->t_numerator1 = (gcnew System::Windows::Forms::TextBox());
			this->t_denumerator1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->t_denumerator2 = (gcnew System::Windows::Forms::TextBox());
			this->t_numerator2 = (gcnew System::Windows::Forms::TextBox());
			this->b_calculate = (gcnew System::Windows::Forms::Button());
			this->l_numerator = (gcnew System::Windows::Forms::Label());
			this->l_denumerator = (gcnew System::Windows::Forms::Label());
			this->cb_sign1 = (gcnew System::Windows::Forms::ComboBox());
			this->cb_sign2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cb_type2 = (gcnew System::Windows::Forms::ComboBox());
			this->cb_type1 = (gcnew System::Windows::Forms::ComboBox());
			this->cb_type3 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->l_error = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(34, 128);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(161, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Тип первого операнда:\r\n";
			this->label1->Click += gcnew System::EventHandler(this, &Calculator::label1_Click);
			// 
			// t_numerator1
			// 
			this->t_numerator1->Location = System::Drawing::Point(79, 70);
			this->t_numerator1->Name = L"t_numerator1";
			this->t_numerator1->Size = System::Drawing::Size(100, 20);
			this->t_numerator1->TabIndex = 2;
			this->t_numerator1->TextChanged += gcnew System::EventHandler(this, &Calculator::t_numerator1_TextChanged);
			// 
			// t_denumerator1
			// 
			this->t_denumerator1->Location = System::Drawing::Point(79, 102);
			this->t_denumerator1->Name = L"t_denumerator1";
			this->t_denumerator1->Size = System::Drawing::Size(100, 20);
			this->t_denumerator1->TabIndex = 3;
			this->t_denumerator1->TextChanged += gcnew System::EventHandler(this, &Calculator::t_denumerator1_TextChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"+", L"-", L"*", L"/" });
			this->comboBox1->Location = System::Drawing::Point(211, 79);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(36, 33);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Calculator::comboBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(267, 128);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(160, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Тип второго операнда:";
			this->label2->Click += gcnew System::EventHandler(this, &Calculator::label2_Click);
			// 
			// t_denumerator2
			// 
			this->t_denumerator2->Location = System::Drawing::Point(312, 102);
			this->t_denumerator2->Name = L"t_denumerator2";
			this->t_denumerator2->Size = System::Drawing::Size(100, 20);
			this->t_denumerator2->TabIndex = 7;
			this->t_denumerator2->TextChanged += gcnew System::EventHandler(this, &Calculator::t_denumerator2_TextChanged);
			// 
			// t_numerator2
			// 
			this->t_numerator2->Location = System::Drawing::Point(312, 70);
			this->t_numerator2->Name = L"t_numerator2";
			this->t_numerator2->Size = System::Drawing::Size(100, 20);
			this->t_numerator2->TabIndex = 8;
			this->t_numerator2->TextChanged += gcnew System::EventHandler(this, &Calculator::t_numerator2_TextChanged);
			// 
			// b_calculate
			// 
			this->b_calculate->BackColor = System::Drawing::Color::Peru;
			this->b_calculate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b_calculate->Location = System::Drawing::Point(454, 191);
			this->b_calculate->Name = L"b_calculate";
			this->b_calculate->Size = System::Drawing::Size(120, 30);
			this->b_calculate->TabIndex = 9;
			this->b_calculate->Text = L"Вычислить";
			this->b_calculate->UseVisualStyleBackColor = false;
			this->b_calculate->Click += gcnew System::EventHandler(this, &Calculator::b_calculate_Click);
			// 
			// l_numerator
			// 
			this->l_numerator->AutoSize = true;
			this->l_numerator->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->l_numerator->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->l_numerator->Location = System::Drawing::Point(501, 70);
			this->l_numerator->MinimumSize = System::Drawing::Size(100, 20);
			this->l_numerator->Name = L"l_numerator";
			this->l_numerator->Size = System::Drawing::Size(100, 20);
			this->l_numerator->TabIndex = 10;
			this->l_numerator->Click += gcnew System::EventHandler(this, &Calculator::l_numerator_Click);
			// 
			// l_denumerator
			// 
			this->l_denumerator->AutoSize = true;
			this->l_denumerator->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->l_denumerator->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->l_denumerator->Location = System::Drawing::Point(501, 105);
			this->l_denumerator->MinimumSize = System::Drawing::Size(100, 20);
			this->l_denumerator->Name = L"l_denumerator";
			this->l_denumerator->Size = System::Drawing::Size(100, 20);
			this->l_denumerator->TabIndex = 11;
			this->l_denumerator->Click += gcnew System::EventHandler(this, &Calculator::l_denumerator_Click);
			// 
			// cb_sign1
			// 
			this->cb_sign1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cb_sign1->FormattingEnabled = true;
			this->cb_sign1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"+", L"-" });
			this->cb_sign1->Location = System::Drawing::Point(37, 79);
			this->cb_sign1->Name = L"cb_sign1";
			this->cb_sign1->Size = System::Drawing::Size(36, 33);
			this->cb_sign1->TabIndex = 12;
			// 
			// cb_sign2
			// 
			this->cb_sign2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cb_sign2->FormattingEnabled = true;
			this->cb_sign2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"+", L"-" });
			this->cb_sign2->Location = System::Drawing::Point(270, 79);
			this->cb_sign2->Name = L"cb_sign2";
			this->cb_sign2->Size = System::Drawing::Size(36, 33);
			this->cb_sign2->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(186, 48);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(105, 17);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Тип операции:\r\n";
			this->label3->Click += gcnew System::EventHandler(this, &Calculator::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(454, 79);
			this->label4->MinimumSize = System::Drawing::Size(36, 33);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 33);
			this->label4->TabIndex = 15;
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->Click += gcnew System::EventHandler(this, &Calculator::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(451, 48);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(148, 17);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Результат операции:";
			this->label5->Click += gcnew System::EventHandler(this, &Calculator::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(418, 83);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(30, 31);
			this->label6->TabIndex = 17;
			this->label6->Text = L"=";
			// 
			// cb_type2
			// 
			this->cb_type2->FormattingEnabled = true;
			this->cb_type2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"обыкновенная дробь", L"десятичная дробь" });
			this->cb_type2->Location = System::Drawing::Point(270, 148);
			this->cb_type2->Name = L"cb_type2";
			this->cb_type2->Size = System::Drawing::Size(151, 21);
			this->cb_type2->TabIndex = 18;
			this->cb_type2->SelectedIndexChanged += gcnew System::EventHandler(this, &Calculator::cb_type2_SelectedIndexChanged);
			// 
			// cb_type1
			// 
			this->cb_type1->FormattingEnabled = true;
			this->cb_type1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"обыкновенная дробь", L"десятичная дробь" });
			this->cb_type1->Location = System::Drawing::Point(37, 148);
			this->cb_type1->Name = L"cb_type1";
			this->cb_type1->Size = System::Drawing::Size(151, 21);
			this->cb_type1->TabIndex = 19;
			this->cb_type1->SelectedIndexChanged += gcnew System::EventHandler(this, &Calculator::cb_type1_SelectedIndexChanged);
			// 
			// cb_type3
			// 
			this->cb_type3->BackColor = System::Drawing::SystemColors::Window;
			this->cb_type3->FormattingEnabled = true;
			this->cb_type3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"обыкновенная дробь", L"десятичная дробь" });
			this->cb_type3->Location = System::Drawing::Point(454, 148);
			this->cb_type3->Name = L"cb_type3";
			this->cb_type3->Size = System::Drawing::Size(151, 21);
			this->cb_type3->TabIndex = 20;
			this->cb_type3->SelectedIndexChanged += gcnew System::EventHandler(this, &Calculator::cb_type3_SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(451, 128);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(116, 17);
			this->label7->TabIndex = 21;
			this->label7->Text = L"Тип результата:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(1, 9);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(478, 25);
			this->label8->TabIndex = 22;
			this->label8->Text = L"Калькулятор обыкновенных и десятичных дробей";
			// 
			// l_error
			// 
			this->l_error->AutoSize = true;
			this->l_error->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->l_error->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->l_error->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->l_error->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->l_error->Location = System::Drawing::Point(37, 191);
			this->l_error->MinimumSize = System::Drawing::Size(300, 30);
			this->l_error->Name = L"l_error";
			this->l_error->Size = System::Drawing::Size(300, 30);
			this->l_error->TabIndex = 23;
			// 
			// Calculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SeaGreen;
			this->ClientSize = System::Drawing::Size(644, 247);
			this->Controls->Add(this->l_error);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->cb_type3);
			this->Controls->Add(this->cb_type1);
			this->Controls->Add(this->cb_type2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->cb_sign2);
			this->Controls->Add(this->cb_sign1);
			this->Controls->Add(this->l_denumerator);
			this->Controls->Add(this->l_numerator);
			this->Controls->Add(this->b_calculate);
			this->Controls->Add(this->t_numerator2);
			this->Controls->Add(this->t_denumerator2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->t_denumerator1);
			this->Controls->Add(this->t_numerator1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Calculator";
			this->Text = L"Calculator";
			this->Load += gcnew System::EventHandler(this, &Calculator::Calculator_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: int getNumerator(System::Windows::Forms::TextBox^ t_source, bool& t_ready) {
		try {
			int num = System::Convert::ToInt32(t_source->Text);
			if (num >= 0) {
				t_ready = true;
				t_source->ResetBackColor();
				return num;
			}
			else throw exception();
		}
		catch (...) {
			t_source->BackColor = Color::Red;
			t_ready = false;
			l_error->Text = "Ошибка! Неправильный ввод!";
			return NOVALUE;
		}
	}
	private: int getDenumerator(System::Windows::Forms::TextBox^ t_source, bool& t_ready) {
		try {
			int num = System::Convert::ToInt32(t_source->Text);
			if (num > 0) {
				t_ready = true;
				t_source->ResetBackColor();
				return num;
			}
			else throw exception();
		}
		catch (...) {
			t_source->BackColor = Color::Red;
			t_ready = false;
			l_error->Text = "Ошибка! Неправильный ввод!";
			return NOVALUE;
		}
	}
	private: double getDouble(System::Windows::Forms::TextBox^ t_source, bool& t_ready) {
		try {
			double num = System::Convert::ToDouble(t_source->Text);
			t_ready = true;
			t_source->ResetBackColor();
			return num;
		}
		catch (...) {
			l_error->Text = "Ошибка! Неправильный ввод!";
			t_source->BackColor = Color::Red;
			t_ready = false;
			return 0;
		}
	}
	


	private: System::Void Calculator_Load(System::Object^ sender, System::EventArgs^ e) {
		comboBox1->DropDownStyle = ComboBoxStyle::DropDownList;
		comboBox1->SelectedIndex = 0;
		cb_sign1->DropDownStyle = ComboBoxStyle::DropDownList;
		cb_sign1->SelectedIndex = 0;
		cb_sign2->DropDownStyle = ComboBoxStyle::DropDownList;
		cb_sign2->SelectedIndex = 0;
		cb_type1->DropDownStyle = ComboBoxStyle::DropDownList;
		cb_type1->SelectedIndex = 0;
		cb_type2->DropDownStyle = ComboBoxStyle::DropDownList;
		cb_type2->SelectedIndex = 0;
		cb_type3->DropDownStyle = ComboBoxStyle::DropDownList;
		cb_type3->SelectedIndex = 0;
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void t_numerator1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void t_denumerator1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void t_numerator2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void t_denumerator2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void b_calculate_Click(System::Object^ sender, System::EventArgs^ e) {	
		try {
			char operation = comboBox1->Text[0];
			if (cb_type1->SelectedIndex == 0) {
				int numer1 = getNumerator(t_numerator1, t_numerator1_ready);
				int denumer1 = getDenumerator(t_denumerator1, t_denumerator1_ready);
				if (t_numerator1_ready && t_denumerator1_ready) {
					cFraction cf1;
					cf1.setSign(cb_sign1->Text[0] == '+' ? 1 : -1);
					cf1.setNumer(numer1);
					cf1.setDenumer(denumer1);
					if (cb_type2->SelectedIndex == 0) {
						int numer2 = getNumerator(t_numerator2, t_numerator2_ready);
						int denumer2 = getDenumerator(t_denumerator2, t_denumerator2_ready);
						if (t_numerator2_ready && t_denumerator2_ready) {
							cFraction cf2;
							cf2.setSign(cb_sign2->Text[0] == '+' ? 1 : -1);
							cf2.setNumer(numer2);
							cf2.setDenumer(denumer2);
							cFraction result;
							switch (operation) {
							case '+': result = cf1 + cf2; break;
							case '-': result = cf1 - cf2; break;
							case '*': result = cf1 * cf2; break;
							case '/': result = cf1 / cf2; break;
							}
							if (cb_type3->SelectedIndex == 0) {
								l_numerator->Text = System::Convert::ToString(result.getNumer());
								l_denumerator->Text = System::Convert::ToString(result.getDenumer());
								if (result.getSign() == 1) label4->Text = "+";
								else label4->Text = "-";							
							}
							else {
								l_denumerator->Text = System::Convert::ToString(result.toDouble());
							}
							l_error->Text = "";
						}
					}
					else {
						double f2 = getDouble(t_denumerator2, t_denumerator2_ready);
						if (t_denumerator2_ready) {
							if (cb_type3->SelectedIndex == 0) {
								cFraction result;
								switch (operation) {
								case '+': result = cf1 + f2; break;
								case '-': result = cf1 - f2; break;
								case '*': result = cf1 * f2; break;
								case '/': result = cf1 / f2; break;
								}
								l_numerator->Text = System::Convert::ToString(result.getNumer());
								l_denumerator->Text = System::Convert::ToString(result.getDenumer());
								if (result.getSign() == 1) label4->Text = "+";
								else label4->Text = "-";
							}
							else {
								double result;
								switch (operation) {
								case '+': result = cf1.toDouble() + f2; break;
								case '-': result = cf1.toDouble() - f2; break;
								case '*': result = cf1.toDouble() * f2; break;
								case '/': result = cf1.toDouble() / f2; break;
								}
								l_denumerator->Text = System::Convert::ToString(result);
							}
							l_error->Text = "";
						}
					}
				}
			}
			else {
				double f1 = getDouble(t_denumerator1, t_denumerator1_ready);
				if (cb_type2->SelectedIndex == 0) {
					int numer2 = getNumerator(t_numerator2, t_numerator2_ready);
					int denumer2 = getDenumerator(t_denumerator2, t_denumerator2_ready);
					if (t_numerator2_ready && t_denumerator2_ready) {
						cFraction cf2;
						cf2.setSign(cb_sign2->Text[0] == '+' ? 1 : -1);
						cf2.setNumer(numer2);
						cf2.setDenumer(denumer2);
						cFraction result;
						switch (operation) {
						case '+': result = cf2 + f1; break;
						case '-': result = (cf2 * -1) + f1; break;
						case '*': result = cf2 * f1; break;
						case '/': result = cf2.getReverse() * f1; break;
						}
						if (cb_type3->SelectedIndex == 0) {
							l_numerator->Text = System::Convert::ToString(result.getNumer());
							l_denumerator->Text = System::Convert::ToString(result.getDenumer());
							if (result.getSign() == 1) label4->Text = "+";
							else label4->Text = "-";
						}
						else {
							l_denumerator->Text = System::Convert::ToString(result.toDouble());
						}
						l_error->Text = "";
					}
				}
				else {
					double f2 = getDouble(t_denumerator2, t_denumerator2_ready);
					if (t_denumerator2_ready) {
						double result;
						switch (operation) {
						case '+': result = f1 + f2; break;
						case '-': result = f1 - f2; break;
						case '*': result = f1 * f2; break;
						case '/': result = f1 / f2; break;
						}
						if (cb_type3->SelectedIndex == 0) {
							l_numerator->Text = System::Convert::ToString(cFraction::toCFraction(result).getNumer());
							l_denumerator->Text = System::Convert::ToString(cFraction::toCFraction(result).getDenumer());
							if (cFraction::toCFraction(result).getSign() == 1) label4->Text = "+";
							else label4->Text = "-";
						}
						else {

							l_denumerator->Text = System::Convert::ToString(result);
						}
						l_error->Text = "";
					}
				}
			}
		}
		catch (...) {
			l_error->Text = "Непридвиденная ошибка!";
		}
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void l_numerator_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void l_denumerator_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void cb_type1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cb_type1->SelectedIndex == 0) {
			t_numerator1->Visible = true;
			cb_sign1->Visible = true;
		}
		else {
			t_numerator1->Visible = false;
			cb_sign1->Visible = false;
		}
	}
	private: System::Void cb_type2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cb_type2->SelectedIndex == 0) {
			t_numerator2->Visible = true;
			cb_sign2->Visible = true;
		}
		else {
			t_numerator2->Visible = false;
			cb_sign2->Visible = false;
		}
	}
	private: System::Void cb_type3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cb_type3->SelectedIndex == 0) {
			l_numerator->Visible = true;
			label4->Visible = true;
		}
		else {
			l_numerator->Visible = false;
			label4->Visible = false;
		}
	}
};
}
