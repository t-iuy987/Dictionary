/*******************************/
/*  Dictionary using Trie Tree */
/*  Data Structure CL2001      */
/*  Final Project              */
/*  19F0405 Section 3C         */
/*******************************/

#include "Home.h" //Add main 'Home' form
#include"Trie.h" //including trie tree class 
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(cli::array<System::String^>^ args) //main function 
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Dictionary::Home); //runs the application
}
