#include "Adapter.h"

Adapter::Adapter()
{
}


void Adapter::init(Object^ form)
{
	System::Windows::Forms::Form^ form1 = (System::Windows::Forms::Form^)form;
	System::Windows::Forms::RichTextBox^ rt_message = (System::Windows::Forms::RichTextBox^)form1->Controls->Find((System::String^)"rt_message", true)[0];
	System::Windows::Forms::RichTextBox^ rt_return  = (System::Windows::Forms::RichTextBox^)form1->Controls->Find((System::String^)"rt_return", true)[0];
	
	System::Windows::Forms::TextBox^ rt_return  = (System::Windows::Forms::TextBox^)form1->Controls->Find((System::String^)"rt_return", true)[0];
}