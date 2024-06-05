#pragma once
#include "SearchEngine.h"
#include <msclr/marshal_cppstd.h>
#include "MyForm1.h"
#include "MyForm2.h"
namespace projectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
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
			engine = new SearchEngine();
			engine->indexDirectory("D:\\Muhammad Ali Riaz");
			openPage = new vector<bool>();
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
			delete engine;
			delete openPage;
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListView^ listView1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^ button2;
		   SearchEngine* engine;
	private: System::Windows::Forms::Button^ button3;
		   vector<bool>* openPage;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 45, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(70, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(525, 104);
			this->label1->TabIndex = 0;
			this->label1->Text = L"MySearchMate";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(150, 168);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(350, 34);
			this->textBox1->TabIndex = 1;
			this->textBox1->WordWrap = false;
			this->textBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::textBox1_MouseClick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Control;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(275, 228);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 35);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Go";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listView1
			// 
			this->listView1->AutoArrange = false;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(86, 269);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(506, 171);
			this->listView1->TabIndex = 3;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::List;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(495, 546);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 35);
			this->button2->TabIndex = 4;
			this->button2->Text = L"History";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(86, 546);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 35);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Exit";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(672, 743);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::White;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//string^ temp = textBox1->Text();
		vector<string>* resultsVector = new vector<string>();


		string temp = msclr::interop::marshal_as<string>(textBox1->Text);
		openPage->push_back(false);
		engine->search(temp,resultsVector);
		listView1->Items->Clear();

		
		if (!resultsVector->empty()) {
			// Iterate through resultsVector and add items to listView1
			for (const string& result : *resultsVector) {
				ListViewItem^ item = gcnew ListViewItem(gcnew String(result.c_str()));
				listView1->Items->Add(item);
			}
		}
		else {
			// If resultsVector is empty, add a single item to listView1 indicating no results found
			ListViewItem^ item = gcnew ListViewItem("No results found.");
			listView1->Items->Add(item);
		}
		listView1->Show();
		// Delete the dynamically allocated resultsVector
		delete resultsVector;
	
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
//private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
//	listView1->Hide();
//}
	   //private: System::Void listView1_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
		  // // Check if an item is selected
		  // if (listView1->SelectedItems->Count > 0) {
			 //  // Get the text of the selected item
			 //  String^ selectedItemText = listView1->SelectedItems[0]->Text;

			 //  // Add the selected item's text to the ListView
			 //  ListViewItem^ item = gcnew ListViewItem(selectedItemText);
			 //  listView1->Items->Add(item);
		  // }
	   //}
private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	// Check if an item is selected
	string temp;
	if (listView1->SelectedItems->Count > 0) {
		String^ selectedItemText = listView1->SelectedItems[0]->Text;
		string selectedItemStr = msclr::interop::marshal_as<string>(selectedItemText);
		openPage->push_back(true);
		for (const WebPage& page : engine->pages) {
			if (page.url == selectedItemStr) {
				engine->history.push_back(selectedItemStr);
				temp = page.content;
				cout << "\n" << endl;
				break; // No need to continue looping once the page is found
			}
		}
		MyForm1^ form1 = gcnew MyForm1(temp);
		form1->Show();
	}
		
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm2^ form1 = gcnew MyForm2(engine, openPage);
		form1->Show();

}
private: System::Void textBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	textBox1->Text = "";
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = "Search here..";
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}
};
}
