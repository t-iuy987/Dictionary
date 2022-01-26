#pragma once

#include<string>
#include <msclr/marshal_cppstd.h> //for converting from String^ to std::string 
namespace Dictionary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// this form is for inserting a word in the dictionary 
	/// </summary>
	public ref class AddWord : public System::Windows::Forms::Form
	{
	public:
		AddWord(void) //ctor 
		{
			InitializeComponent();
			
		}
	


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddWord() //ctor
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ addbtn;
	private: System::Windows::Forms::TextBox^ wordtextbox;
	protected:


	private: System::Windows::Forms::TextBox^ meantextbox;

	private: System::Windows::Forms::Label^ wordlabel;
	private: System::Windows::Forms::Label^ meanlabel;
	private: System::Windows::Forms::Label^ label1;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddWord::typeid));
			this->addbtn = (gcnew System::Windows::Forms::Button());
			this->wordtextbox = (gcnew System::Windows::Forms::TextBox());
			this->meantextbox = (gcnew System::Windows::Forms::TextBox());
			this->wordlabel = (gcnew System::Windows::Forms::Label());
			this->meanlabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// addbtn
			// 
			this->addbtn->BackColor = System::Drawing::Color::MidnightBlue;
			this->addbtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addbtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->addbtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addbtn->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->addbtn->Location = System::Drawing::Point(181, 334);
			this->addbtn->Name = L"addbtn";
			this->addbtn->Size = System::Drawing::Size(75, 23);
			this->addbtn->TabIndex = 2;
			this->addbtn->Text = L"Add";
			this->addbtn->UseVisualStyleBackColor = false;
			this->addbtn->Click += gcnew System::EventHandler(this, &AddWord::addbtn_Click);
			// 
			// wordtextbox
			// 
			this->wordtextbox->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->wordtextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->wordtextbox->Location = System::Drawing::Point(131, 120);
			this->wordtextbox->Multiline = true;
			this->wordtextbox->Name = L"wordtextbox";
			this->wordtextbox->Size = System::Drawing::Size(181, 24);
			this->wordtextbox->TabIndex = 4;
			// 
			// meantextbox
			// 
			this->meantextbox->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->meantextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->meantextbox->Location = System::Drawing::Point(131, 181);
			this->meantextbox->Multiline = true;
			this->meantextbox->Name = L"meantextbox";
			this->meantextbox->Size = System::Drawing::Size(181, 130);
			this->meantextbox->TabIndex = 5;
			// 
			// wordlabel
			// 
			this->wordlabel->AutoSize = true;
			this->wordlabel->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->wordlabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.75F));
			this->wordlabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->wordlabel->Location = System::Drawing::Point(50, 120);
			this->wordlabel->Name = L"wordlabel";
			this->wordlabel->Size = System::Drawing::Size(53, 20);
			this->wordlabel->TabIndex = 6;
			this->wordlabel->Text = L"Word:";
			// 
			// meanlabel
			// 
			this->meanlabel->AutoSize = true;
			this->meanlabel->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->meanlabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.75F));
			this->meanlabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->meanlabel->Location = System::Drawing::Point(46, 179);
			this->meanlabel->Name = L"meanlabel";
			this->meanlabel->Size = System::Drawing::Size(79, 20);
			this->meanlabel->TabIndex = 7;
			this->meanlabel->Text = L"Meaning:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 23.75F));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(37, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 39);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Insert a word";
			// 
			// AddWord
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(609, 511);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->meanlabel);
			this->Controls->Add(this->wordlabel);
			this->Controls->Add(this->meantextbox);
			this->Controls->Add(this->wordtextbox);
			this->Controls->Add(this->addbtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"AddWord";
			this->Text = L"AddWord";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: String^ getWord() //for getting the text in the word field of the form 
		{
			return wordtextbox->Text;
		}
		public: String^ getMean()//for getting the text in the meaning  field of the form 
		{
			return meantextbox->Text;
		}
	private: System::Void addbtn_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (wordtextbox->Text == "" || meantextbox->Text == "") //when npthing's in the boxes yet, display an appropriate message if user tries to add a word 
		{
			MessageBox::Show("Can't Add word.");
		}
		//hide the form 
		this->Hide();
	}
};
}
