#pragma once
#include"AddWord.h" //form for inserting a word 
#include"Trie.h" //trie adt class
#include<string>
#include <msclr/marshal_cppstd.h> //for converting from String^ to std::string

namespace Dictionary {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//creating a dictionary 
	Trie myDictionary;

	
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home(void) //ctor 
		{
			InitializeComponent(); //initializes all the components of teh form
			pnlsuggest->Hide(); //hide the suggestions panel 
			
		}

	protected:
		
		~Home() //dtor
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ dictio;
	protected:

	protected:

	private: System::Windows::Forms::Button^ searchbtn;
	private: System::Windows::Forms::TextBox^ searchBox;
	private: System::Windows::Forms::TextBox^ displaytextbox;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ deletebtn;
	private: System::Windows::Forms::Button^ insertbtn;
	private: System::Windows::Forms::Button^ suggestbtn;
	private: System::Windows::Forms::ListBox^ wordList;
	private: System::Windows::Forms::Panel^ pnlsuggest;
	private: System::Windows::Forms::Label^ suggestlbl;
	private: System::Windows::Forms::TextBox^ suggestbox;

	private: System::Windows::Forms::Button^ okbtn;
	private: System::Windows::Forms::Label^ wlabel;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
			this->dictio = (gcnew System::Windows::Forms::Label());
			this->searchbtn = (gcnew System::Windows::Forms::Button());
			this->searchBox = (gcnew System::Windows::Forms::TextBox());
			this->displaytextbox = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->deletebtn = (gcnew System::Windows::Forms::Button());
			this->insertbtn = (gcnew System::Windows::Forms::Button());
			this->suggestbtn = (gcnew System::Windows::Forms::Button());
			this->wordList = (gcnew System::Windows::Forms::ListBox());
			this->pnlsuggest = (gcnew System::Windows::Forms::Panel());
			this->okbtn = (gcnew System::Windows::Forms::Button());
			this->suggestbox = (gcnew System::Windows::Forms::TextBox());
			this->suggestlbl = (gcnew System::Windows::Forms::Label());
			this->wlabel = (gcnew System::Windows::Forms::Label());
			this->pnlsuggest->SuspendLayout();
			this->SuspendLayout();
			// 
			// dictio
			// 
			this->dictio->AutoSize = true;
			this->dictio->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dictio->Font = (gcnew System::Drawing::Font(L"Century Gothic", 24.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dictio->ForeColor = System::Drawing::SystemColors::Control;
			this->dictio->Location = System::Drawing::Point(68, 25);
			this->dictio->Name = L"dictio";
			this->dictio->Size = System::Drawing::Size(179, 40);
			this->dictio->TabIndex = 0;
			this->dictio->Text = L"Dictionary";
			this->dictio->Click += gcnew System::EventHandler(this, &Home::label1_Click);
			// 
			// searchbtn
			// 
			this->searchbtn->BackColor = System::Drawing::Color::Black;
			this->searchbtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->searchbtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->searchbtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchbtn->ForeColor = System::Drawing::SystemColors::Control;
			this->searchbtn->Location = System::Drawing::Point(118, 163);
			this->searchbtn->Name = L"searchbtn";
			this->searchbtn->Size = System::Drawing::Size(75, 25);
			this->searchbtn->TabIndex = 1;
			this->searchbtn->Text = L"Search";
			this->searchbtn->UseVisualStyleBackColor = false;
			this->searchbtn->Click += gcnew System::EventHandler(this, &Home::searchbtn_Click);
			// 
			// searchBox
			// 
			this->searchBox->BackColor = System::Drawing::SystemColors::InfoText;
			this->searchBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->searchBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->searchBox->ForeColor = System::Drawing::SystemColors::Control;
			this->searchBox->Location = System::Drawing::Point(38, 121);
			this->searchBox->Multiline = true;
			this->searchBox->Name = L"searchBox";
			this->searchBox->Size = System::Drawing::Size(242, 25);
			this->searchBox->TabIndex = 2;
			this->searchBox->TextChanged += gcnew System::EventHandler(this, &Home::textBox1_TextChanged);
			// 
			// displaytextbox
			// 
			this->displaytextbox->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->displaytextbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->displaytextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->displaytextbox->Location = System::Drawing::Point(38, 335);
			this->displaytextbox->Multiline = true;
			this->displaytextbox->Name = L"displaytextbox";
			this->displaytextbox->ReadOnly = true;
			this->displaytextbox->Size = System::Drawing::Size(242, 119);
			this->displaytextbox->TabIndex = 3;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Control;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Location = System::Drawing::Point(38, 144);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(242, 2);
			this->panel1->TabIndex = 4;
			// 
			// deletebtn
			// 
			this->deletebtn->BackColor = System::Drawing::Color::MidnightBlue;
			this->deletebtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->deletebtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->deletebtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->deletebtn->ForeColor = System::Drawing::SystemColors::Control;
			this->deletebtn->Location = System::Drawing::Point(118, 253);
			this->deletebtn->Name = L"deletebtn";
			this->deletebtn->Size = System::Drawing::Size(75, 23);
			this->deletebtn->TabIndex = 5;
			this->deletebtn->Text = L"Delete";
			this->deletebtn->UseVisualStyleBackColor = false;
			this->deletebtn->Click += gcnew System::EventHandler(this, &Home::deletebtn_Click);
			// 
			// insertbtn
			// 
			this->insertbtn->BackColor = System::Drawing::Color::MidnightBlue;
			this->insertbtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->insertbtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->insertbtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->insertbtn->ForeColor = System::Drawing::SystemColors::Control;
			this->insertbtn->Location = System::Drawing::Point(118, 207);
			this->insertbtn->Name = L"insertbtn";
			this->insertbtn->Size = System::Drawing::Size(75, 23);
			this->insertbtn->TabIndex = 6;
			this->insertbtn->Text = L"Insert";
			this->insertbtn->UseVisualStyleBackColor = false;
			this->insertbtn->Click += gcnew System::EventHandler(this, &Home::insertbtn_Click);
			// 
			// suggestbtn
			// 
			this->suggestbtn->BackColor = System::Drawing::Color::MidnightBlue;
			this->suggestbtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->suggestbtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->suggestbtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suggestbtn->ForeColor = System::Drawing::SystemColors::Control;
			this->suggestbtn->Location = System::Drawing::Point(118, 295);
			this->suggestbtn->Name = L"suggestbtn";
			this->suggestbtn->Size = System::Drawing::Size(75, 23);
			this->suggestbtn->TabIndex = 7;
			this->suggestbtn->Text = L"Suggest";
			this->suggestbtn->UseVisualStyleBackColor = false;
			this->suggestbtn->Click += gcnew System::EventHandler(this, &Home::suggestbtn_Click);
			// 
			// wordList
			// 
			this->wordList->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->wordList->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->wordList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->wordList->FormattingEnabled = true;
			this->wordList->ItemHeight = 16;
			this->wordList->Location = System::Drawing::Point(367, 47);
			this->wordList->Name = L"wordList";
			this->wordList->Size = System::Drawing::Size(195, 402);
			this->wordList->Sorted = true;
			this->wordList->TabIndex = 9;
			this->wordList->SelectedIndexChanged += gcnew System::EventHandler(this, &Home::wordList_SelectedIndexChanged);
			// 
			// pnlsuggest
			// 
			this->pnlsuggest->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pnlsuggest->Controls->Add(this->okbtn);
			this->pnlsuggest->Controls->Add(this->suggestbox);
			this->pnlsuggest->Controls->Add(this->suggestlbl);
			this->pnlsuggest->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlsuggest->Location = System::Drawing::Point(0, 0);
			this->pnlsuggest->Name = L"pnlsuggest";
			this->pnlsuggest->Size = System::Drawing::Size(609, 511);
			this->pnlsuggest->TabIndex = 10;
			// 
			// okbtn
			// 
			this->okbtn->BackColor = System::Drawing::Color::MidnightBlue;
			this->okbtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->okbtn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->okbtn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold));
			this->okbtn->ForeColor = System::Drawing::Color::GhostWhite;
			this->okbtn->Location = System::Drawing::Point(409, 429);
			this->okbtn->Name = L"okbtn";
			this->okbtn->Size = System::Drawing::Size(83, 34);
			this->okbtn->TabIndex = 2;
			this->okbtn->Text = L"OK";
			this->okbtn->UseVisualStyleBackColor = false;
			this->okbtn->Click += gcnew System::EventHandler(this, &Home::okbtn_Click);
			// 
			// suggestbox
			// 
			this->suggestbox->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->suggestbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->suggestbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->suggestbox->ForeColor = System::Drawing::SystemColors::Control;
			this->suggestbox->Location = System::Drawing::Point(62, 102);
			this->suggestbox->Multiline = true;
			this->suggestbox->Name = L"suggestbox";
			this->suggestbox->ReadOnly = true;
			this->suggestbox->Size = System::Drawing::Size(430, 296);
			this->suggestbox->TabIndex = 1;
			this->suggestbox->TextChanged += gcnew System::EventHandler(this, &Home::suggestbox_TextChanged);
			// 
			// suggestlbl
			// 
			this->suggestlbl->AutoSize = true;
			this->suggestlbl->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suggestlbl->ForeColor = System::Drawing::SystemColors::Control;
			this->suggestlbl->Location = System::Drawing::Point(56, 37);
			this->suggestlbl->Name = L"suggestlbl";
			this->suggestlbl->Size = System::Drawing::Size(168, 33);
			this->suggestlbl->TabIndex = 0;
			this->suggestlbl->Text = L"Suggestions";
			// 
			// wlabel
			// 
			this->wlabel->AutoSize = true;
			this->wlabel->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->wlabel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->wlabel->ForeColor = System::Drawing::SystemColors::Control;
			this->wlabel->Location = System::Drawing::Point(35, 101);
			this->wlabel->Name = L"wlabel";
			this->wlabel->Size = System::Drawing::Size(41, 17);
			this->wlabel->TabIndex = 3;
			this->wlabel->Text = L"Word";
			// 
			// Home
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(609, 511);
			this->Controls->Add(this->pnlsuggest);
			this->Controls->Add(this->wordList);
			this->Controls->Add(this->suggestbtn);
			this->Controls->Add(this->insertbtn);
			this->Controls->Add(this->deletebtn);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->displaytextbox);
			this->Controls->Add(this->searchBox);
			this->Controls->Add(this->searchbtn);
			this->Controls->Add(this->dictio);
			this->Controls->Add(this->wlabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Home";
			this->Text = L"Home";
			this->TransparencyKey = System::Drawing::Color::White;
			this->Load += gcnew System::EventHandler(this, &Home::Home_Load);
			this->pnlsuggest->ResumeLayout(false);
			this->pnlsuggest->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		if (searchBox->Text != "") //if some word is tyoed in the search box 
		{
			int index = wordList->FindString(searchBox->Text); //if the wordList has the word typed in the search box, move its index in the 'index'
			if (index != -1)
				wordList->SetSelected(index, true); //select the word with the index 'index'
			else
				wordList->ClearSelected();

		}

	}
	private: System::Void Home_Load(System::Object^ sender, System::EventArgs^ e)  //when the Home form loads 
	{
		ifstream file;
		file.open("Dictionary.txt"); //open the file 'Dictionary' 

		string str;
		//if file opens, add every word from the file in the wordList listbox 
		if (file.is_open())
		{
			while (getline(file, str)) //get the words
			{
				String^ word = gcnew String(str.c_str());
				wordList->Items->Add(word);
				getline(file, str); //skipping to the next word
			}
		}
	}

	private: System::Void searchbtn_Click(System::Object^ sender, System::EventArgs^ e) //when user clicks on the serach button 
	{
		displaytextbox->Text = ""; //clear the displaytextbox 

		//converting the String^ in search box to string 
		string str = msclr::interop::marshal_as<std::string>(searchBox->Text->ToString());

		if (myDictionary.searchBool(str) == false) //if word is not in the dictionary, display appropriate message 
		{
			displaytextbox->Text = "Word not found.";
		}
		else
		{
			//selected item = the item user searched for from the dictionary 
			//get the selected item from the listbox 'wordList' and change it to string 
			string str = msclr::interop::marshal_as<std::string>(wordList->SelectedItem->ToString());

			//display the string 'Meaning' in the displaytextbox 
			displaytextbox->Text += "Meaning: ";

			//get the meaning of the word and display it in the displaytextbox 
			string means = myDictionary.getMeaning(str);
			means = myDictionary.getMeaning(str);

			//c_str returns a const char* that points to a null-terminated string (i.e. a C-style string).
			String^ mean = gcnew String(means.c_str()); 
			displaytextbox->Text += mean;//display the meaning in the displaytextbox 
		}
	}

	private: System::Void wordList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void insertbtn_Click(System::Object^ sender, System::EventArgs^ e) //when user clicks on the insert button 
	{
		AddWord^ insertForm = gcnew AddWord; //create an instance of 'AddWord' form
		insertForm->ShowDialog(); //display the form 

		//get the word along with its meaning from the 'AddWord' and store them in the 'word' and 'meaning' strings respectively 
		string word = msclr::interop::marshal_as<std::string>(insertForm->getWord());
		string meaning = msclr::interop::marshal_as<std::string>(insertForm->getMean());

		if (myDictionary.searchBool(word)) //if the word is already in the dictionary, display appropriate message 
		{
			MessageBox::Show("Word already exist.");

		}
		else if (word != "" || meaning != "") //if word and meaning are not empty, add the word 
		{
			myDictionary.insert(word, meaning); //insert the word 
			insertForm->Close(); //close the form 
			MessageBox::Show("Word Added."); //show appropriate message 

			//add the word in the wordList as well 
			String^ Word = gcnew String(word.c_str());
			wordList->Items->Add(Word);
		}

	}

	private: System::Void deletebtn_Click(System::Object^ sender, System::EventArgs^ e) //when user clicks on the delete button 
	{
		string word = msclr::interop::marshal_as<std::string>(searchBox->Text->ToString()); //get the text in search box 

		if (!myDictionary.searchBool(word)) //if word is not in the dictionary 
		{
			displaytextbox->Text = "Choose an appropriate word.";
		}
		else
		{
			string word = msclr::interop::marshal_as<std::string>(wordList->SelectedItem->ToString());
			myDictionary.Delete(word); //delete the word 
			wordList->Items->Remove(wordList->SelectedItem); //remove it from the listbox 
			MessageBox::Show("Word Deleted!"); //display message 
		}
	}
	private: System::Void suggestbtn_Click(System::Object^ sender, System::EventArgs^ e) //when user clicks on the suggest button 
	{
		pnlsuggest->Show(); //display the suggest panel 
		string word1, word2, word3; //declare three words 
		myDictionary.suggest(word1, word2, word3); //store the suggestions in the 3 words 
		if (word1 == "" && word2 == "" && word3 == "") // if all words are empty , display appropriate message 
		{
			suggestbox->Text = "No suggestions yet.";
			return;
		}
		
		suggestbox->Text = ""; //empty the suggestion box 

		//store the words as String^
		String^ Word1 = gcnew String(word1.c_str());
		String^ Word2 = gcnew String(word2.c_str());
		String^ Word3 = gcnew String(word3.c_str());

		//store the meaning of word1
		String^ mean = gcnew String(myDictionary.getMeaning(word1).c_str());

		//display word1 and its meaning 
		suggestbox->Text += (Word1 + " \r\n");
		suggestbox->Text += (mean + " \r\n");

		//store the meaning of word2
		mean = gcnew String(myDictionary.getMeaning(word2).c_str());

		//display word2 and its meaning 
		suggestbox->Text += (Word2 + " \r\n");
		suggestbox->Text += (mean + " \r\n");

		//store the meaning of word3
		mean = gcnew String(myDictionary.getMeaning(word3).c_str());

		//display word3 and its meaning 
		suggestbox->Text += (Word3 + " \r\n");
		suggestbox->Text += (mean + " \r\n");
	}
	private: System::Void okbtn_Click(System::Object^ sender, System::EventArgs^ e) //when user clicks on the ok button
	{
		pnlsuggest->Hide();  //hide the suggestion panel 
		
	}
	private: System::Void suggestbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}
	};
}
