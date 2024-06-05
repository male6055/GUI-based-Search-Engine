#pragma once
#include  <vector>
#include <iostream>
#include "SearchEngine.h"
#include "MyForm1.h"
namespace projectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		MyForm2(SearchEngine* eng, std::vector<bool>* Page)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			openPage = new std::vector<bool>();
			openPage = Page;
			engine = new SearchEngine();
			engine = eng;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
			delete engine;
			delete openPage;
		}
	private: System::Windows::Forms::ListView^ listView1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		std::vector<bool>* openPage;
		SearchEngine* engine;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
		  
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(66, 115);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(531, 450);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::List;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm2::listView1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold));
			this->button1->Location = System::Drawing::Point(497, 636);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 35);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 45, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->label1->Location = System::Drawing::Point(202, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(245, 92);
			this->label1->TabIndex = 2;
			this->label1->Text = L"History";
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(672, 743);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
		vector<string>* resultsVector = new vector<string>();
		string temp;
		engine->showHistory(resultsVector);
		for (const string& result : *resultsVector) {
			ListViewItem^ item = gcnew ListViewItem(gcnew String(result.c_str()));
			listView1->Items->Add(item);
		}

	}
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		string temp;
		if (listView1->SelectedItems->Count > 0) {
			String^ selectedItemText = listView1->SelectedItems[0]->Text;
			int selectedIndex = listView1->SelectedIndices[0];
			string selectedItemStr = msclr::interop::marshal_as<string>(selectedItemText);
			int i = 0;
			for (const WebPage& page : engine->pages) {
				if (page.url == selectedItemStr) {
					temp = page.content;
					cout << "\n" << endl;
					break; // No need to continue looping once the page is found
				}
			}
			if (openPage->at(selectedIndex) == true) {
				MyForm1^ form1 = gcnew MyForm1(temp);
				form1->Show();
			}
			
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
};
}
