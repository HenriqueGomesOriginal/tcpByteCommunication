#pragma once

namespace TcpByteComunication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lb_ipClient;
	protected:
	private: System::Windows::Forms::TextBox^  tb_host;
	private: System::Windows::Forms::Label^  lb_port;
	private: System::Windows::Forms::TextBox^  tb_port;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lb_ipClient = (gcnew System::Windows::Forms::Label());
			this->tb_host = (gcnew System::Windows::Forms::TextBox());
			this->lb_port = (gcnew System::Windows::Forms::Label());
			this->tb_port = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lb_ipClient
			// 
			this->lb_ipClient->AutoSize = true;
			this->lb_ipClient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_ipClient->Location = System::Drawing::Point(12, 19);
			this->lb_ipClient->Name = L"lb_ipClient";
			this->lb_ipClient->Size = System::Drawing::Size(56, 25);
			this->lb_ipClient->TabIndex = 0;
			this->lb_ipClient->Text = L"Host";
			// 
			// tb_host
			// 
			this->tb_host->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F));
			this->tb_host->Location = System::Drawing::Point(98, 12);
			this->tb_host->Name = L"tb_host";
			this->tb_host->Size = System::Drawing::Size(307, 31);
			this->tb_host->TabIndex = 1;
			// 
			// lb_port
			// 
			this->lb_port->AutoSize = true;
			this->lb_port->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_port->Location = System::Drawing::Point(12, 61);
			this->lb_port->Name = L"lb_port";
			this->lb_port->Size = System::Drawing::Size(51, 25);
			this->lb_port->TabIndex = 2;
			this->lb_port->Text = L"Port";
			// 
			// tb_port
			// 
			this->tb_port->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F));
			this->tb_port->Location = System::Drawing::Point(98, 55);
			this->tb_port->Name = L"tb_port";
			this->tb_port->Size = System::Drawing::Size(307, 31);
			this->tb_port->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 112);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 25);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Message";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(12, 150);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(393, 101);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(17, 270);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(103, 20);
			this->radioButton1->TabIndex = 6;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Send as Hex";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// richTextBox2
			// 
			this->richTextBox2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(12, 349);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(393, 101);
			this->richTextBox2->TabIndex = 8;
			this->richTextBox2->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 306);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 25);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Return";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 481);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 29);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Send";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(298, 481);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(107, 29);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(425, 537);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tb_port);
			this->Controls->Add(this->lb_port);
			this->Controls->Add(this->tb_host);
			this->Controls->Add(this->lb_ipClient);
			this->Name = L"MyForm";
			this->Text = L"TcpByteComunication";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
