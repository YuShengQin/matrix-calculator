#pragma once
#include"DataManager.h"
#include "MyVector.h"
#include"DotNetUtilities.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include<string>
#include<iostream>

using namespace msclr::interop;

namespace WindowsFormsApplication_cpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// WindowsForm 的摘要
	/// </summary>
	public ref class WindowsForm : public System::Windows::Forms::Form
	{
	public:
		WindowsForm(void)
		{
			InitializeComponent();
			dataManager = new DataManager();
			lastInputLength = -1;
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~WindowsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  FileToolStripMenuItem;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStripMenuItem^  LoadVectorToolStripMenuItem;















	protected:















	protected:

	private:
		/// <summary>
			DataManager* dataManager;
			String^ userInput;
			int lastInputLength;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Label^  InputLabel;
	private: System::Windows::Forms::TextBox^  Input;
	private: System::Windows::Forms::Label^  VectorLabel;
	private: System::Windows::Forms::ListBox^  VectorList;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::Label^  OutputLabel;
	private: System::Windows::Forms::Button^  ClearButton;
	private: System::Windows::Forms::TextBox^  Output;

			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LoadVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->OutputLabel = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ClearButton = (gcnew System::Windows::Forms::Button());
			this->VectorList = (gcnew System::Windows::Forms::ListBox());
			this->VectorLabel = (gcnew System::Windows::Forms::Label());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->InputLabel = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->menuStrip2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip2
			// 
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Padding = System::Windows::Forms::Padding(9, 3, 0, 3);
			this->menuStrip2->Size = System::Drawing::Size(1049, 33);
			this->menuStrip2->TabIndex = 1;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// FileToolStripMenuItem
			// 
			this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->LoadVectorToolStripMenuItem });
			this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			this->FileToolStripMenuItem->Size = System::Drawing::Size(51, 27);
			this->FileToolStripMenuItem->Text = L"File";
			// 
			// LoadVectorToolStripMenuItem
			// 
			this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
			this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(194, 30);
			this->LoadVectorToolStripMenuItem->Text = L"Load Vector";
			this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadVectorToolStripMenuItem_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 33);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 612)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1049, 612);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openFileDialog1_FileOk);
			// 
			// Output
			// 
			this->Output->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Output->Location = System::Drawing::Point(4, 57);
			this->Output->Margin = System::Windows::Forms::Padding(4);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ReadOnly = true;
			this->Output->Size = System::Drawing::Size(457, 557);
			this->Output->TabIndex = 1;
			// 
			// OutputLabel
			// 
			this->OutputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OutputLabel->AutoSize = true;
			this->OutputLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->OutputLabel->Location = System::Drawing::Point(4, 15);
			this->OutputLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->OutputLabel->Name = L"OutputLabel";
			this->OutputLabel->Size = System::Drawing::Size(73, 23);
			this->OutputLabel->TabIndex = 0;
			this->OutputLabel->Text = L"Output";
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->OutputLabel);
			this->flowLayoutPanel2->Controls->Add(this->ClearButton);
			this->flowLayoutPanel2->Controls->Add(this->Output);
			this->flowLayoutPanel2->Location = System::Drawing::Point(4, 4);
			this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(480, 595);
			this->flowLayoutPanel2->TabIndex = 1;
			// 
			// ClearButton
			// 
			this->ClearButton->Location = System::Drawing::Point(84, 3);
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size(75, 47);
			this->ClearButton->TabIndex = 4;
			this->ClearButton->Text = L"Clear";
			this->ClearButton->UseVisualStyleBackColor = true;
			this->ClearButton->Click += gcnew System::EventHandler(this, &WindowsForm::ClearButton_Click);
			// 
			// VectorList
			// 
			this->VectorList->FormattingEnabled = true;
			this->VectorList->ItemHeight = 18;
			this->VectorList->Location = System::Drawing::Point(4, 293);
			this->VectorList->Margin = System::Windows::Forms::Padding(4);
			this->VectorList->Name = L"VectorList";
			this->VectorList->Size = System::Drawing::Size(485, 292);
			this->VectorList->TabIndex = 3;
			// 
			// VectorLabel
			// 
			this->VectorLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->VectorLabel->AutoSize = true;
			this->VectorLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->VectorLabel->Location = System::Drawing::Point(213, 266);
			this->VectorLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->VectorLabel->Name = L"VectorLabel";
			this->VectorLabel->Size = System::Drawing::Size(67, 23);
			this->VectorLabel->TabIndex = 2;
			this->VectorLabel->Text = L"Vector";
			// 
			// Input
			// 
			this->Input->Location = System::Drawing::Point(4, 27);
			this->Input->Margin = System::Windows::Forms::Padding(4);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(285, 235);
			this->Input->TabIndex = 1;
			this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged);
			// 
			// InputLabel
			// 
			this->InputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->InputLabel->AutoSize = true;
			this->InputLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->InputLabel->Location = System::Drawing::Point(218, 0);
			this->InputLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->InputLabel->Name = L"InputLabel";
			this->InputLabel->Size = System::Drawing::Size(57, 23);
			this->InputLabel->TabIndex = 0;
			this->InputLabel->Text = L"Input";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->InputLabel);
			this->flowLayoutPanel1->Controls->Add(this->Input);
			this->flowLayoutPanel1->Controls->Add(this->VectorLabel);
			this->flowLayoutPanel1->Controls->Add(this->VectorList);
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(539, 4);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(500, 604);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// WindowsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1049, 645);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip2);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"WindowsForm";
			this->Text = L"VectorExample";
			this->Load += gcnew System::EventHandler(this, &WindowsForm::WindowsForm_Load);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void WindowsForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void LoadVectorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//開啟Dialog
	openFileDialog1->ShowDialog();
}

private: System::Void Input_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	//當Input textbox中的輸入改變時，便會進入此函式
	//取得向量資料
	std::vector<Vector> vectors = dataManager->GetVectors();
	std::vector<Matrix> matrixs = dataManager->GetMatrixs();
	std::ofstream fout("output.txt");
	//判斷輸入自元為'\n'，並防止取到字串-1位置
	if (Input->Text->Length-1 >= 0 &&Input->Text[Input->Text->Length - 1] == '\n')
	{
		//將使用者輸入字串(在userInput中)，依空白作切割
		array<String^> ^userCommand = userInput->Split(' ');
		//字串比較，若指令為"print"的情況
		if (userCommand[0] == "print")
		{
			//定意輸出暫存
			String^ outputTemp = "";
			//透過for迴圈，從向量資料中找出對應變數
			for (unsigned int i = 0; i < vectors.size();i++)
			{
				//若變數名稱與指令變數名稱符合
				if (userCommand[1] == gcnew String(vectors[i].Name.c_str()))
				{
					//將輸出格式存入暫存
					outputTemp += "[";
					//將輸出資料存入暫存
					for (unsigned int j = 0; j< vectors[i].Data.size(); j++)
					{
						outputTemp += vectors[i].Data[j].ToString();
						if (j != vectors[i].Data.size() - 1)
							outputTemp += ",";
					}
					//將輸出格式存入暫存，並且換行
					outputTemp += "]" + Environment::NewLine;
					//輸出暫存資訊
					Output->Text += gcnew String(vectors[i].Name.c_str()) +" = "+ outputTemp;
					break;
				}
			}
		}
		//反之則判斷找不到指令
		else
		{
			InputToPostfix Input;
			marshal_context^ context = gcnew marshal_context();
			std::string str = context->marshal_as<std::string>(userCommand[0]);
		    Input.Postfix(str);
			
			std::string tmps = Input.result;
			Output->Text += gcnew String(tmps.c_str()) + Environment::NewLine;

			int offsetIndex = 0, judgeFlag = -1, result = -1;
			bool check = false, findOperator = false, updateStr = false, detFlag = false, MatrixF = false, EigenF = false;
			std::vector<double> sum;
			std::vector<Vector> LinearSystem;
			Eigen eigen;
			while (tmps.size() > 1) {
				Vector tmpv;
				Matrix tmpm;
				std::string tmpValue = "";
				int a = 0, b = 0;
				bool loopflag = false;
				if (check) break;
				for (int i = 0; i < tmps.size(); i++) {
					if (check) break;
					if (loopflag) break;
					if (Input.priority(tmps[i])) {
						switch (tmps[i]) {
						case '+':
							a = tmps[i - 2] - 'A' + Input.index;
							b = tmps[i - 1] - 'A' + Input.index;
							if(!dataManager->mode) tmpv = vectors[a] + vectors[b];
							else tmpm = matrixs[a] + matrixs[b];
							if (!tmpv.flag || !tmpm.flag) {
								check = true;
								break;
							}
							if(!dataManager->mode) vectors[a] = tmpv;
							else matrixs[a] = tmpm;
							updateStr = false;
							break;
						case '-':
							a = tmps[i - 2] - 'A' + Input.index;
							b = tmps[i - 1] - 'A' + Input.index;

							if (!dataManager->mode) tmpv = vectors[a] - vectors[b];
							else tmpm = matrixs[a] - matrixs[b];

							if (!tmpv.flag || !tmpm.flag) {
								check = true;
								break;
							}

							if (!dataManager->mode) vectors[a] = tmpv;
							else matrixs[a] = tmpm;

							updateStr = false;
							break;
						case '*':
							a = tmps[i - 2] - 'A' + Input.index;
							b = tmps[i - 1] - 'A' + Input.index;

							if (!dataManager->mode) tmpv = vectors[a] * vectors[b];
							else tmpm = matrixs[a] * matrixs[b];

							if (!dataManager->mode) vectors[a] = tmpv;
							else matrixs[a] = tmpm;

							if (!tmpv.flag || !tmpm.flag) {
								check = true;
								break;
							}
							updateStr = false;
							break;
						case '/':
							a = tmps[i - 2] - 'A' + Input.index;
							b = tmps[i - 1] - 'A' + Input.index;

							if (!dataManager->mode) tmpv = vectors[a] / vectors[b];
							else tmpm = matrixs[a] / matrixs[b];

							if (!tmpv.flag || !tmpm.flag) {
								check = true;
								break;
							}

							if (!dataManager->mode) vectors[a] = tmpv;
							else matrixs[a] = tmpm;

							updateStr = false;
							break;
						case '!':		//norm	&	rank
							a = tmps[i - 1] - 'A' + Input.index;
							if (!dataManager->mode) tmpv = vectors[a].norm();
							else result = matrixs[a].rank();

							if (!dataManager->mode) vectors[a] = tmpv;
							updateStr = true;
							break;
						case '@':		//normal	&	transpose
							a = tmps[i - 1] - 'A' + Input.index;
							if (!dataManager->mode) tmpv = vectors[a].normal();
							else tmpm = matrixs[a].transpose();

							if (!tmpm.flag) {
								check = true;
								break;
							}

							if (!dataManager->mode) vectors[a] = tmpv;
							else matrixs[a] = tmpm;
							updateStr = true;
							break;
						case '#':		//cross	&	LinearSystem
							a = tmps[i - 2] - 'A' + Input.index;
							b = tmps[i - 1] - 'A' + Input.index;

							if (!dataManager->mode) tmpv = vectors[a].cross(vectors[b]);
							else tmpm = matrixs[a].LinearSystem(matrixs[b]);

							
							if (!tmpv.flag || !tmpm.flag) {
								check = true;
								break;
							}

							if (!dataManager->mode) vectors[a] = tmpv;
							else matrixs[a] = tmpm;

							updateStr = false;
							break;
						case '$':		//com	&	LeastSquare
							a = tmps[i - 2] - 'A' + Input.index;
							b = tmps[i - 1] - 'A' + Input.index;

							if (!dataManager->mode) tmpv = vectors[a].com(vectors[b]);
							else tmpm = matrixs[a].LeastSquare(matrixs[b]);

							if (!tmpv.flag || !tmpm.flag) {
								check = true;
								break;
							}

							if (!dataManager->mode) vectors[a] = tmpv;
							else  matrixs[a] = tmpm;
							updateStr = false;
							break;
						case '%':		//proj	&	Eigen
							b = tmps[i - 1] - 'A' + Input.index;
							if (!dataManager->mode) {
								a = tmps[i - 2] - 'A' + Input.index;
								tmpv = vectors[a].proj(vectors[b]);
							}
							else {
								eigen = matrixs[b].FindEigen();
								EigenF = true;
							}

							if (!tmpv.flag || !eigen.flag) {
								check = true;
								break;
							}
							
							if (!dataManager->mode) {
								vectors[a] = tmpv;
								updateStr = false;
							}else updateStr = true;
							
							
							break;
						case '7':		//area	&	rref
							a = tmps[i - 2] - 'A' + Input.index;
							b = tmps[i - 1] - 'A' + Input.index;
							if (!dataManager->mode) {
								tmpv = vectors[a].area(vectors[b]);
							}
							else {
								tmpm = matrixs[a].rref(tmps[i - 1]);
							}
							
							if (!tmpv.flag || !tmpm.flag) {
								check = true;
								break;
							}
							if (!dataManager->mode) {
								vectors[a] = tmpv;
							}
							else matrixs[a] = tmpm;
							updateStr = false;
							break;
						case '&':		//isparallel
							a = tmps[i - 2] - 'A' + Input.index;
							b = tmps[i - 1] - 'A' + Input.index;
							judgeFlag = vectors[a].parallel(vectors[b]);
							if (judgeFlag == -1) {
								check = true;
								break;
							}
							updateStr = false;
							break;
						case '1':		//orthogonal
							a = tmps[i - 2] - 'A' + Input.index;
							b = tmps[i - 1] - 'A' + Input.index;
							judgeFlag = vectors[a].orthogonal(vectors[b]);
							if (judgeFlag == -1) {
								check = true;
								break;
							}
							updateStr = false;
							break;
						case '2':		//angle
							a = tmps[i - 2] - 'A' + Input.index;
							b = tmps[i - 1] - 'A' + Input.index;
							tmpv = vectors[a].angle(vectors[b]);
							vectors[a] = tmpv;
							if (!tmpv.flag) {
								check = true;
								break;
							}
							updateStr = false;
							break;
						case '3':		//angle
							a = tmps[i - 2] - 'A' + Input.index;
							b = tmps[i - 1] - 'A' + Input.index;
							for (int j = a; j <= b; j++) {
								LinearSystem.push_back(vectors[j]);
							}
							judgeFlag = vectors[a].isLi(LinearSystem);
						//	Output->Text += "Det : " + judgeFlag.ToString() + Environment::NewLine;
							if (judgeFlag == -1) {
								check = true;
								break;
							}
							updateStr = false;
							break;
						case '4':		//Det
							a = tmps[i - 1] - 'A' + Input.index;
							sum = matrixs[a].Det();
							detFlag = true;
							updateStr = true;
							break;
						case '5':		//adjoint
							a = tmps[i - 1] - 'A' + Input.index;
							tmpm = matrixs[a].adjoint();
							if (!tmpm.flag) {
								check = true;
								break;
							}
							matrixs[a] = tmpm;
							updateStr = true;
							break;

						case '6':		//inverse
							a = tmps[i - 1] - 'A';
							std::cout << "inversing\n";
							matrixs[a] = matrixs[a].inverse();
							std::cout << "inverse complete\n";
							if (!matrixs[a].flag) {
								check = true;
								break;
							}
							updateStr = true;
							break;

						case '9':
							b = tmps[i - 1] - 'A' + Input.index;
							eigen = matrixs[b].PowerMethodEigen();
							if (!eigen.flag) {
								check = true;
								break;
							}
							EigenF = true;
							updateStr = true;
							break;


						case '8':		//OrthonormalBasis
							a = tmps[i - 2] - 'A' + Input.index;
							b = tmps[i - 1] - 'A' + Input.index;
							for (int j = a; j <= b; j++) {
								LinearSystem.push_back(vectors[j]);
							}
							LinearSystem = vectors[a].OrthonormalBasis(LinearSystem);
							if (!LinearSystem[0].flag) {
								check = true;
								break;
							}
							Matrix tmpM;
							tmpM.row = LinearSystem.size();
							tmpM.col = LinearSystem[0].Dimension;
							for (int j = 0; j < LinearSystem.size(); j++)
								tmpM.Data.push_back(LinearSystem[j].Data);
							matrixs.push_back(tmpM);
							MatrixF = true;
							updateStr = false;
							a = 0;
							break;

						}
						if (check) break;
						if (!updateStr) {
							tmpValue.assign(tmps, i - 2, 1);
							tmps.replace(i - 2, 3, tmpValue);
						}
						else {
							tmpValue.assign(tmps, i - 1, 1);
							tmps.replace(i - 1, 2, tmpValue);
						}
						offsetIndex = a;
						loopflag = true;
						findOperator = true;
					}
				}
			}
			if (check || !findOperator) {
				std::cout << "illegal Input!\n";
				Output->Text += "illegal Input!" + Environment::NewLine;
			}
			else if (judgeFlag != -1) {
				if(judgeFlag != 0) Output->Text += "Yes" + Environment::NewLine;
				else Output->Text += "No" + Environment::NewLine;
			}
			else if (detFlag) {
				std::cout << "Det output\n";
				Output->Text += sum[0].ToString() + Environment::NewLine;
			}
			else if (result != -1) {
				std::cout << "result output\n";
				Output->Text += result.ToString() + Environment::NewLine;
			}
			else if (EigenF) {
				std::cout << "Eigen output\n";
				Output->Text += "v =" + Environment::NewLine;
				Output->Text += " [";
				fout << "v =\n[";
				int vecSize = eigen.vectors.size();
				//std::cout << vecSize;
				
				for (int j = 0; j < vecSize; j++) {
					for (int k = 0; k < eigen.vectors[j].size(); k++) {
						std::string scalarString;
						if(vecSize == 1) scalarString = std::to_string(eigen.vectors[j][k]);
						else scalarString  = std::to_string(eigen.vectors[k][j]);
						Output->Text += gcnew String(scalarString.c_str());
						fout << scalarString;
						if (k == eigen.vectors[j].size() - 1) {
							if (j == eigen.vectors.size() - 1) {
								Output->Text += "]";
								fout << "]";
							}
							Output->Text += Environment::NewLine;
							fout << "\n";
						}
						if ((k != eigen.vectors[j].size() - 1) || (j != eigen.vectors.size() - 1)) {
							Output->Text += ",";
							fout << ",";
						}
					}
				}
				
				Output->Text += "d =" + Environment::NewLine;
				Output->Text += " [";
				fout << "d =\n[";
				for (int j = 0; j < eigen.values.size(); j++) {
					for (int k = 0; k < eigen.values.size(); k++) {
						if (j == k) {
							std::string scalarString = std::to_string(eigen.values[j]);
							Output->Text += gcnew String(scalarString.c_str());
							fout << scalarString;
						}
						else {
							Output->Text += "0";
							fout << "0";
						}
						if (k == eigen.values.size() - 1) {
							if (j == eigen.vectors.size() - 1) {
								Output->Text += "]";
								fout << "]";
							}
							Output->Text += Environment::NewLine;
							fout << "\n";
						}
						if ((k != eigen.values.size() - 1) || (j != eigen.values.size() - 1)) {
							Output->Text += ",";
							fout << ",";
						}
					}
				}
			}
			else if(!dataManager->mode && !MatrixF){
				std::cout << "Vector output\n";
				Output->Text += " [";
				fout << " [";
				for (unsigned int j = 0; j < vectors[offsetIndex].Data.size(); j++)
				{
					std::string scalarString = std::to_string(vectors[offsetIndex].Data[j]);
					Output->Text += gcnew String(scalarString.c_str());
					fout << scalarString;
					if (j != vectors[offsetIndex].Data.size() - 1) {
						Output->Text += ",";
						fout << ",";
					}
				}
					//將輸出格式存入暫存
				Output->Text += "]";
				Output->Text += Environment::NewLine;
				fout << "]\n";
			}
			else {
				std::cout << "Matrix Output\n";
				bool checkSize = matrixs[offsetIndex].row > 10 ? true : false;
				fout << " [";
				if(!checkSize)
				Output->Text += " [";
				std::cout << "Row : " << matrixs[offsetIndex].row << "\n";
				std::cout << "Col : " << matrixs[offsetIndex].col << "\n";
				for (int j = 0; j < matrixs[offsetIndex].row; j++) {
					for (int k = 0; k < matrixs[offsetIndex].col; k++) {
						std::string scalarString = std::to_string(matrixs[offsetIndex].Data[j][k]);
						fout << scalarString;
						if(!checkSize)
						Output->Text += gcnew String(scalarString.c_str());
						if (k == matrixs[offsetIndex].col - 1) {
							if (j == matrixs[offsetIndex].row - 1) {
								if (!checkSize)
								Output->Text += "]";
								fout << "]";
							}
							fout << std::endl;
							if (!checkSize)
							Output->Text += Environment::NewLine;
						}
						if ((k != matrixs[offsetIndex].col - 1) || (j != matrixs[offsetIndex].row - 1)) {
							if(!checkSize)
							Output->Text += ",";
							fout << ",";
						}
					}
				}
			}
		}
		userInput = "";
	}
	else
	{
		//將使用者輸入字串(在Text box中)，依'\n'作切割
		array<String^> ^userCommand = Input->Text->Split('\n');
		//並將最後一行，作為目前使用者輸入指令
		userInput = userCommand[userCommand->Length-1];
	}
}

private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
{
	//在Dialog按下OK便會進入此函式
	//字串轉制string^ to string
	std::string tempFileName;
	MarshalString(openFileDialog1->FileName, tempFileName);
	//將檔案路徑名稱傳入dataManager
	dataManager->SetFileName(tempFileName);
	//從讀取讀取向量資料
	if (dataManager->LoadVectorData())
	{
		//將VectorList中項目先做清除
		VectorList->Items->Clear();	
		//取得所有向量資料
		std::vector<Vector> vectors = dataManager->GetVectors();
		std::vector<Matrix> matrixs = dataManager->GetMatrixs();
		if (!dataManager->mode) {
			for (unsigned int i = 0; i < vectors.size(); i++)
			{
				//將檔案名稱存入暫存
				std::string tempString = vectors[i].Name;
				//將輸出格式存入暫存
				tempString += " [";
				//將輸出資料存入暫存
				for (unsigned int j = 0; j<vectors[i].Data.size(); j++)
				{
					std::string scalarString = std::to_string(vectors[i].Data[j]);
					tempString += scalarString.substr(0, scalarString.size() - 5);
					if (j != vectors[i].Data.size() - 1)
						tempString += ",";
				}
				//將輸出格式存入暫存
				tempString += "]";
				//將項目加入VectorList中
				VectorList->Items->Add(gcnew String(tempString.c_str()));
			}
			Output->Text += "-Vector datas have been loaded-" + Environment::NewLine;
		}
		else {
			for (unsigned int i = 0; i < matrixs.size(); i++)
			{
				//將檔案名稱存入暫存
				System::String^ str;
				std::string tempString = "";
				VectorList->Items->Add(gcnew String(matrixs[i].Name.c_str()));
				//將輸出格式存入暫存
				tempString += " [";
				//將輸出資料存入暫存
				for (unsigned int j = 0; j< matrixs[i].row; j++)
				{
					for (int k = 0; k < matrixs[i].col; k++) {
						std::string scalarString = std::to_string(matrixs[i].Data[j][k]);
						tempString += scalarString.substr(0, scalarString.size() - 5);
						if ((j != matrixs[i].row - 1) || (k != matrixs[i].col-1))
							tempString += ",";
					}
					if (j == matrixs[i].row - 1) tempString += "]";
					str = gcnew String(tempString.c_str());
					VectorList->Items->Add(str);
					tempString = "";
				}
				//將輸出格式存入暫存
			}
			Output->Text += "-Matrix datas have been loaded-" + Environment::NewLine;
		}
	}
}

private: System::Void ClearButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Output->Clear();
	Input->Clear();
}
};
}
