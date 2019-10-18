#pragma once
#include "Adapter.h"

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
			rb_hex->Checked = true;

			char* buf = (char*)malloc(400000);

			FILE* reader;
			fopen_s(&reader, "bin95.txt", "rb");
			fread(buf, 400000, 1, reader);
			

			int dec[1024];
			for (int i = 0; i < 95; i++)
			{
				dec[i] = (int)buf[i];
			}

			fclose(reader);
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
	private: System::Windows::Forms::RichTextBox^  rt_message;
	private: System::Windows::Forms::RadioButton^  rb_hex;


	private: System::Windows::Forms::RichTextBox^  rt_return;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  bt_send;
	private: System::Windows::Forms::Button^  bt_clear;
	private: System::Windows::Forms::RadioButton^  rb_ascii;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->lb_ipClient = (gcnew System::Windows::Forms::Label());
			this->tb_host = (gcnew System::Windows::Forms::TextBox());
			this->lb_port = (gcnew System::Windows::Forms::Label());
			this->tb_port = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->rt_message = (gcnew System::Windows::Forms::RichTextBox());
			this->rb_hex = (gcnew System::Windows::Forms::RadioButton());
			this->rt_return = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bt_send = (gcnew System::Windows::Forms::Button());
			this->bt_clear = (gcnew System::Windows::Forms::Button());
			this->rb_ascii = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// lb_ipClient
			// 
			this->lb_ipClient->AutoSize = true;
			this->lb_ipClient->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_ipClient->Location = System::Drawing::Point(12, 22);
			this->lb_ipClient->Name = L"lb_ipClient";
			this->lb_ipClient->Size = System::Drawing::Size(56, 25);
			this->lb_ipClient->TabIndex = 0;
			this->lb_ipClient->Text = L"Host";
			// 
			// tb_host
			// 
			this->tb_host->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F));
			this->tb_host->Location = System::Drawing::Point(98, 15);
			this->tb_host->Name = L"tb_host";
			this->tb_host->Size = System::Drawing::Size(307, 31);
			this->tb_host->TabIndex = 1;
			// 
			// lb_port
			// 
			this->lb_port->AutoSize = true;
			this->lb_port->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_port->Location = System::Drawing::Point(12, 64);
			this->lb_port->Name = L"lb_port";
			this->lb_port->Size = System::Drawing::Size(51, 25);
			this->lb_port->TabIndex = 2;
			this->lb_port->Text = L"Port";
			// 
			// tb_port
			// 
			this->tb_port->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F));
			this->tb_port->Location = System::Drawing::Point(98, 58);
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
			// rt_message
			// 
			this->rt_message->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rt_message->Location = System::Drawing::Point(12, 150);
			this->rt_message->Name = L"rt_message";
			this->rt_message->Size = System::Drawing::Size(393, 101);
			this->rt_message->TabIndex = 5;
			this->rt_message->Text = L"";
			// 
			// rb_hex
			// 
			this->rb_hex->AutoSize = true;
			this->rb_hex->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rb_hex->Location = System::Drawing::Point(17, 270);
			this->rb_hex->Name = L"rb_hex";
			this->rb_hex->Size = System::Drawing::Size(103, 20);
			this->rb_hex->TabIndex = 6;
			this->rb_hex->TabStop = true;
			this->rb_hex->Text = L"Send as Hex";
			this->rb_hex->UseVisualStyleBackColor = true;
			// 
			// rt_return
			// 
			this->rt_return->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->rt_return->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rt_return->Location = System::Drawing::Point(12, 349);
			this->rt_return->Name = L"rt_return";
			this->rt_return->ReadOnly = true;
			this->rt_return->Size = System::Drawing::Size(393, 101);
			this->rt_return->TabIndex = 8;
			this->rt_return->Text = L"";
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
			// bt_send
			// 
			this->bt_send->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_send->Location = System::Drawing::Point(13, 481);
			this->bt_send->Name = L"bt_send";
			this->bt_send->Size = System::Drawing::Size(107, 29);
			this->bt_send->TabIndex = 9;
			this->bt_send->Text = L"Send";
			this->bt_send->UseVisualStyleBackColor = true;
			this->bt_send->Click += gcnew System::EventHandler(this, &MyForm::bt_send_Click);
			// 
			// bt_clear
			// 
			this->bt_clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_clear->Location = System::Drawing::Point(298, 481);
			this->bt_clear->Name = L"bt_clear";
			this->bt_clear->Size = System::Drawing::Size(107, 29);
			this->bt_clear->TabIndex = 10;
			this->bt_clear->Text = L"Clear";
			this->bt_clear->UseVisualStyleBackColor = true;
			this->bt_clear->Click += gcnew System::EventHandler(this, &MyForm::bt_clear_Click);
			// 
			// rb_ascii
			// 
			this->rb_ascii->AutoSize = true;
			this->rb_ascii->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rb_ascii->Location = System::Drawing::Point(159, 270);
			this->rb_ascii->Name = L"rb_ascii";
			this->rb_ascii->Size = System::Drawing::Size(112, 20);
			this->rb_ascii->TabIndex = 11;
			this->rb_ascii->TabStop = true;
			this->rb_ascii->Text = L"Send as ASCII";
			this->rb_ascii->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->ClientSize = System::Drawing::Size(425, 537);
			this->Controls->Add(this->rb_ascii);
			this->Controls->Add(this->bt_clear);
			this->Controls->Add(this->bt_send);
			this->Controls->Add(this->rt_return);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->rb_hex);
			this->Controls->Add(this->rt_message);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tb_port);
			this->Controls->Add(this->lb_port);
			this->Controls->Add(this->tb_host);
			this->Controls->Add(this->lb_ipClient);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"TcpByteComunication";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bt_send_Click(System::Object^  sender, System::EventArgs^  e) {
		Adapter^ adapter = gcnew Adapter();
		adapter->init(this);
	}
private: System::Void bt_clear_Click(System::Object^  sender, System::EventArgs^  e) {
	rt_return->Clear();
}
};
}
