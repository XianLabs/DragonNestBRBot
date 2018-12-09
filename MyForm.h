#pragma once
#include "Hooks.hpp"
#include "Hacks.hpp"
#include "Pointer.hpp"
#include "LUAHelper.hpp"
#include <string>
#include <queue>

using namespace std;
extern std::queue<PacketWriter*> SendPacketQueue;
HANDLE ScriptThread; //lua

namespace DragonNestBR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Runtime::InteropServices;

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
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::ListView^  listView_PacketLog;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketLength;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketData;
	private: System::Windows::Forms::TextBox^  textBox_SendPacket;
	private: System::Windows::Forms::Button^  button_SendPacket;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  button_RecvPacket;
	private: System::Windows::Forms::TextBox^  textBox_RecvPacket;
	private: System::Windows::Forms::ListView^  listView_RecvPacketLog;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  button_EndScript;
	private: System::Windows::Forms::Button^  button_RunScript;
	private: System::Windows::Forms::TextBox^  textBox_ScriptText;
	private: System::Windows::Forms::TabPage^  tabPage4;


























	private: System::Windows::Forms::GroupBox^  groupBox_Options;
	private: System::Windows::Forms::TabControl^  tabControl_PacketOptions;
	private: System::Windows::Forms::TabPage^  tabPage_SendTools;
	private: System::Windows::Forms::TextBox^  textBox_SpamPacketDelay;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::CheckBox^  checkBox_SpamPacket;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TabPage^  tabPage_LogTools;
	private: System::Windows::Forms::CheckBox^  checkBox_HookRecv;
	private: System::Windows::Forms::Button^  button_BlockPacket;
	private: System::Windows::Forms::Button^  button_IgnorePacket;
	private: System::Windows::Forms::ListView^  listView_PacketRules;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketRules;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_PacketRulesData;
	private: System::Windows::Forms::Button^  button_ModifyPacket;
	private: System::Windows::Forms::TextBox^  textBox_PacketRule2;
	private: System::Windows::Forms::TextBox^  textBox_PacketRule1;
	private: System::Windows::Forms::CheckBox^  checkBox_HookSend;
	private: System::Windows::Forms::TabPage^  tabPage_Misc;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_DungeonMultiplier;
	private: System::Windows::Forms::CheckBox^  checkBox_SilverFarmBot;
	private: System::Windows::Forms::GroupBox^  groupBox_AutoLogin;
	private: System::Windows::Forms::CheckBox^  checkBox_AutoLogin;
	private: System::Windows::Forms::Label^  label_CharIndex;
	private: System::Windows::Forms::Label^  label_Channel;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_CharID;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_ChannelID;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Label^  label_PosX;
private: System::Windows::Forms::Label^  label_PosY;
private: System::Windows::Forms::Label^  label_PosZ;



	private: System::Windows::Forms::Button^  button1;

	private:
		Thread^ SendLogThread;
		Thread^ SpamPacketThread;
private: System::Windows::Forms::CheckBox^  checkBox_ControlPlayer;
private: System::Windows::Forms::NumericUpDown^  numericUpDown_SpeedHack;
private: System::Windows::Forms::CheckBox^  checkBox_CPUReducer;
private: System::Windows::Forms::CheckBox^  checkBox_NoClip;
private: System::Windows::Forms::CheckBox^  checkBox_SpeedHack;
private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_LogPackets;
private: System::Windows::Forms::ToolStripMenuItem^  copySelectedToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  clearLogToolStripMenuItem;
private: System::Windows::Forms::CheckBox^  checkBox_RamReducer;

private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::Label^  label_Status;
private: System::Windows::Forms::Label^  label_Gold;
private: System::Windows::Forms::Label^  label_MapID;
private: System::Windows::Forms::Label^  label_Name;
private: System::Windows::Forms::CheckBox^  checkBox_NoDelayPetLoot;
private: System::Windows::Forms::Button^  button_SaveScript;
private: System::ComponentModel::IContainer^  components;
		 /// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->listView_PacketLog = (gcnew System::Windows::Forms::ListView());
			this->columnHeader_PacketLength = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_PacketData = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_LogPackets = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->copySelectedToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearLogToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox_SendPacket = (gcnew System::Windows::Forms::TextBox());
			this->button_SendPacket = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button_RecvPacket = (gcnew System::Windows::Forms::Button());
			this->textBox_RecvPacket = (gcnew System::Windows::Forms::TextBox());
			this->listView_RecvPacketLog = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button_SaveScript = (gcnew System::Windows::Forms::Button());
			this->button_EndScript = (gcnew System::Windows::Forms::Button());
			this->button_RunScript = (gcnew System::Windows::Forms::Button());
			this->textBox_ScriptText = (gcnew System::Windows::Forms::TextBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->checkBox_NoDelayPetLoot = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label_Status = (gcnew System::Windows::Forms::Label());
			this->label_Gold = (gcnew System::Windows::Forms::Label());
			this->label_MapID = (gcnew System::Windows::Forms::Label());
			this->label_Name = (gcnew System::Windows::Forms::Label());
			this->checkBox_RamReducer = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_ControlPlayer = (gcnew System::Windows::Forms::CheckBox());
			this->numericUpDown_SpeedHack = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_CPUReducer = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_NoClip = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_SpeedHack = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox_Options = (gcnew System::Windows::Forms::GroupBox());
			this->tabControl_PacketOptions = (gcnew System::Windows::Forms::TabControl());
			this->tabPage_SendTools = (gcnew System::Windows::Forms::TabPage());
			this->textBox_SpamPacketDelay = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->checkBox_SpamPacket = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage_LogTools = (gcnew System::Windows::Forms::TabPage());
			this->checkBox_HookRecv = (gcnew System::Windows::Forms::CheckBox());
			this->button_BlockPacket = (gcnew System::Windows::Forms::Button());
			this->button_IgnorePacket = (gcnew System::Windows::Forms::Button());
			this->listView_PacketRules = (gcnew System::Windows::Forms::ListView());
			this->columnHeader_PacketRules = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_PacketRulesData = (gcnew System::Windows::Forms::ColumnHeader());
			this->button_ModifyPacket = (gcnew System::Windows::Forms::Button());
			this->textBox_PacketRule2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_PacketRule1 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox_HookSend = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage_Misc = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_DungeonMultiplier = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox_SilverFarmBot = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox_AutoLogin = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_AutoLogin = (gcnew System::Windows::Forms::CheckBox());
			this->label_CharIndex = (gcnew System::Windows::Forms::Label());
			this->label_Channel = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_CharID = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_ChannelID = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label_PosX = (gcnew System::Windows::Forms::Label());
			this->label_PosY = (gcnew System::Windows::Forms::Label());
			this->label_PosZ = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->contextMenuStrip_LogPackets->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_SpeedHack))->BeginInit();
			this->groupBox_Options->SuspendLayout();
			this->tabControl_PacketOptions->SuspendLayout();
			this->tabPage_SendTools->SuspendLayout();
			this->tabPage_LogTools->SuspendLayout();
			this->tabPage_Misc->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_DungeonMultiplier))->BeginInit();
			this->groupBox_AutoLogin->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CharID))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_ChannelID))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(3, 2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(512, 346);
			this->tabControl1->TabIndex = 9;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage1->Controls->Add(this->listView_PacketLog);
			this->tabPage1->Controls->Add(this->textBox_SendPacket);
			this->tabPage1->Controls->Add(this->button_SendPacket);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(504, 320);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Send";
			// 
			// listView_PacketLog
			// 
			this->listView_PacketLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView_PacketLog->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->columnHeader_PacketLength,
					this->columnHeader_PacketData
			});
			this->listView_PacketLog->ContextMenuStrip = this->contextMenuStrip_LogPackets;
			this->listView_PacketLog->FullRowSelect = true;
			this->listView_PacketLog->GridLines = true;
			this->listView_PacketLog->Location = System::Drawing::Point(6, 6);
			this->listView_PacketLog->Name = L"listView_PacketLog";
			this->listView_PacketLog->Size = System::Drawing::Size(492, 282);
			this->listView_PacketLog->TabIndex = 1;
			this->listView_PacketLog->UseCompatibleStateImageBehavior = false;
			this->listView_PacketLog->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader_PacketLength
			// 
			this->columnHeader_PacketLength->Text = L"Length";
			// 
			// columnHeader_PacketData
			// 
			this->columnHeader_PacketData->Text = L"Data";
			this->columnHeader_PacketData->Width = 854;
			// 
			// contextMenuStrip_LogPackets
			// 
			this->contextMenuStrip_LogPackets->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->copySelectedToolStripMenuItem,
					this->clearLogToolStripMenuItem
			});
			this->contextMenuStrip_LogPackets->Name = L"contextMenuStrip_LogPackets";
			this->contextMenuStrip_LogPackets->Size = System::Drawing::Size(150, 48);
			// 
			// copySelectedToolStripMenuItem
			// 
			this->copySelectedToolStripMenuItem->Name = L"copySelectedToolStripMenuItem";
			this->copySelectedToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->copySelectedToolStripMenuItem->Text = L"Copy Selected";
			this->copySelectedToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::copySelectedToolStripMenuItem_Click);
			// 
			// clearLogToolStripMenuItem
			// 
			this->clearLogToolStripMenuItem->Name = L"clearLogToolStripMenuItem";
			this->clearLogToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->clearLogToolStripMenuItem->Text = L"Clear Log";
			this->clearLogToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clearLogToolStripMenuItem_Click);
			// 
			// textBox_SendPacket
			// 
			this->textBox_SendPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_SendPacket->Location = System::Drawing::Point(6, 294);
			this->textBox_SendPacket->Name = L"textBox_SendPacket";
			this->textBox_SendPacket->Size = System::Drawing::Size(431, 20);
			this->textBox_SendPacket->TabIndex = 2;
			this->textBox_SendPacket->Text = L"Enter Packet...";
			// 
			// button_SendPacket
			// 
			this->button_SendPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_SendPacket->Location = System::Drawing::Point(443, 294);
			this->button_SendPacket->Name = L"button_SendPacket";
			this->button_SendPacket->Size = System::Drawing::Size(55, 22);
			this->button_SendPacket->TabIndex = 6;
			this->button_SendPacket->Text = L"Send";
			this->button_SendPacket->UseVisualStyleBackColor = true;
			this->button_SendPacket->Click += gcnew System::EventHandler(this, &MyForm::button_SendPacket_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage2->Controls->Add(this->button_RecvPacket);
			this->tabPage2->Controls->Add(this->textBox_RecvPacket);
			this->tabPage2->Controls->Add(this->listView_RecvPacketLog);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(504, 320);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Recv";
			// 
			// button_RecvPacket
			// 
			this->button_RecvPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_RecvPacket->Location = System::Drawing::Point(391, 294);
			this->button_RecvPacket->Name = L"button_RecvPacket";
			this->button_RecvPacket->Size = System::Drawing::Size(55, 22);
			this->button_RecvPacket->TabIndex = 7;
			this->button_RecvPacket->Text = L"Recv";
			this->button_RecvPacket->UseVisualStyleBackColor = true;
			// 
			// textBox_RecvPacket
			// 
			this->textBox_RecvPacket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_RecvPacket->Location = System::Drawing::Point(7, 295);
			this->textBox_RecvPacket->Name = L"textBox_RecvPacket";
			this->textBox_RecvPacket->Size = System::Drawing::Size(379, 20);
			this->textBox_RecvPacket->TabIndex = 3;
			this->textBox_RecvPacket->Text = L"Enter Packet...";
			// 
			// listView_RecvPacketLog
			// 
			this->listView_RecvPacketLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView_RecvPacketLog->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->columnHeader1,
					this->columnHeader2
			});
			this->listView_RecvPacketLog->FullRowSelect = true;
			this->listView_RecvPacketLog->GridLines = true;
			this->listView_RecvPacketLog->Location = System::Drawing::Point(6, 5);
			this->listView_RecvPacketLog->Name = L"listView_RecvPacketLog";
			this->listView_RecvPacketLog->Size = System::Drawing::Size(440, 284);
			this->listView_RecvPacketLog->TabIndex = 2;
			this->listView_RecvPacketLog->UseCompatibleStateImageBehavior = false;
			this->listView_RecvPacketLog->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Length";
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Data";
			this->columnHeader2->Width = 854;
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage3->Controls->Add(this->button_SaveScript);
			this->tabPage3->Controls->Add(this->button_EndScript);
			this->tabPage3->Controls->Add(this->button_RunScript);
			this->tabPage3->Controls->Add(this->textBox_ScriptText);
			this->tabPage3->ForeColor = System::Drawing::SystemColors::Control;
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(504, 320);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"LUA Scripting";
			// 
			// button_SaveScript
			// 
			this->button_SaveScript->BackColor = System::Drawing::Color::Maroon;
			this->button_SaveScript->Location = System::Drawing::Point(357, 294);
			this->button_SaveScript->Name = L"button_SaveScript";
			this->button_SaveScript->Size = System::Drawing::Size(144, 23);
			this->button_SaveScript->TabIndex = 5;
			this->button_SaveScript->Text = L"Save Script";
			this->button_SaveScript->UseVisualStyleBackColor = false;
			// 
			// button_EndScript
			// 
			this->button_EndScript->BackColor = System::Drawing::Color::Chocolate;
			this->button_EndScript->Location = System::Drawing::Point(195, 293);
			this->button_EndScript->Name = L"button_EndScript";
			this->button_EndScript->Size = System::Drawing::Size(156, 23);
			this->button_EndScript->TabIndex = 4;
			this->button_EndScript->Text = L"End Script";
			this->button_EndScript->UseVisualStyleBackColor = false;
			this->button_EndScript->Click += gcnew System::EventHandler(this, &MyForm::button_EndScript_Click);
			// 
			// button_RunScript
			// 
			this->button_RunScript->BackColor = System::Drawing::Color::YellowGreen;
			this->button_RunScript->Location = System::Drawing::Point(3, 293);
			this->button_RunScript->Name = L"button_RunScript";
			this->button_RunScript->Size = System::Drawing::Size(186, 23);
			this->button_RunScript->TabIndex = 3;
			this->button_RunScript->Text = L"Run Script";
			this->button_RunScript->UseVisualStyleBackColor = false;
			this->button_RunScript->Click += gcnew System::EventHandler(this, &MyForm::button_RunScript_Click);
			// 
			// textBox_ScriptText
			// 
			this->textBox_ScriptText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_ScriptText->BackColor = System::Drawing::SystemColors::Window;
			this->textBox_ScriptText->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_ScriptText->Location = System::Drawing::Point(2, 0);
			this->textBox_ScriptText->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox_ScriptText->Multiline = true;
			this->textBox_ScriptText->Name = L"textBox_ScriptText";
			this->textBox_ScriptText->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox_ScriptText->Size = System::Drawing::Size(500, 287);
			this->textBox_ScriptText->TabIndex = 2;
			this->textBox_ScriptText->Text = L"Enter script here (or Download Script)\r\n";
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage4->Controls->Add(this->checkBox_NoDelayPetLoot);
			this->tabPage4->Controls->Add(this->groupBox1);
			this->tabPage4->Controls->Add(this->checkBox_RamReducer);
			this->tabPage4->Controls->Add(this->checkBox_ControlPlayer);
			this->tabPage4->Controls->Add(this->numericUpDown_SpeedHack);
			this->tabPage4->Controls->Add(this->checkBox_CPUReducer);
			this->tabPage4->Controls->Add(this->checkBox_NoClip);
			this->tabPage4->Controls->Add(this->checkBox_SpeedHack);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(504, 320);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Hacks";
			// 
			// checkBox_NoDelayPetLoot
			// 
			this->checkBox_NoDelayPetLoot->AutoSize = true;
			this->checkBox_NoDelayPetLoot->Location = System::Drawing::Point(14, 130);
			this->checkBox_NoDelayPetLoot->Name = L"checkBox_NoDelayPetLoot";
			this->checkBox_NoDelayPetLoot->Size = System::Drawing::Size(101, 17);
			this->checkBox_NoDelayPetLoot->TabIndex = 12;
			this->checkBox_NoDelayPetLoot->Text = L"Instant Pet Loot";
			this->checkBox_NoDelayPetLoot->UseVisualStyleBackColor = true;
			this->checkBox_NoDelayPetLoot->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_NoDelayPetLoot_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label_Status);
			this->groupBox1->Controls->Add(this->label_Gold);
			this->groupBox1->Controls->Add(this->label_MapID);
			this->groupBox1->Controls->Add(this->label_Name);
			this->groupBox1->Location = System::Drawing::Point(292, 8);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 104);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Character Info";
			// 
			// label_Status
			// 
			this->label_Status->AutoSize = true;
			this->label_Status->Location = System::Drawing::Point(8, 81);
			this->label_Status->Name = L"label_Status";
			this->label_Status->Size = System::Drawing::Size(67, 13);
			this->label_Status->TabIndex = 3;
			this->label_Status->Text = L"Status: IDLE";
			// 
			// label_Gold
			// 
			this->label_Gold->AutoSize = true;
			this->label_Gold->Location = System::Drawing::Point(8, 62);
			this->label_Gold->Name = L"label_Gold";
			this->label_Gold->Size = System::Drawing::Size(32, 13);
			this->label_Gold->TabIndex = 2;
			this->label_Gold->Text = L"Gold:";
			// 
			// label_MapID
			// 
			this->label_MapID->AutoSize = true;
			this->label_MapID->Location = System::Drawing::Point(7, 42);
			this->label_MapID->Name = L"label_MapID";
			this->label_MapID->Size = System::Drawing::Size(45, 13);
			this->label_MapID->TabIndex = 1;
			this->label_MapID->Text = L"Map ID:";
			// 
			// label_Name
			// 
			this->label_Name->AutoSize = true;
			this->label_Name->Location = System::Drawing::Point(6, 22);
			this->label_Name->Name = L"label_Name";
			this->label_Name->Size = System::Drawing::Size(38, 13);
			this->label_Name->TabIndex = 0;
			this->label_Name->Text = L"Name:";
			// 
			// checkBox_RamReducer
			// 
			this->checkBox_RamReducer->AutoSize = true;
			this->checkBox_RamReducer->Location = System::Drawing::Point(14, 84);
			this->checkBox_RamReducer->Name = L"checkBox_RamReducer";
			this->checkBox_RamReducer->Size = System::Drawing::Size(125, 17);
			this->checkBox_RamReducer->TabIndex = 10;
			this->checkBox_RamReducer->Text = L"Reduce RAM Usage";
			this->checkBox_RamReducer->UseVisualStyleBackColor = true;
			this->checkBox_RamReducer->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_RamReducer_CheckedChanged);
			// 
			// checkBox_ControlPlayer
			// 
			this->checkBox_ControlPlayer->AutoSize = true;
			this->checkBox_ControlPlayer->Location = System::Drawing::Point(14, 107);
			this->checkBox_ControlPlayer->Name = L"checkBox_ControlPlayer";
			this->checkBox_ControlPlayer->Size = System::Drawing::Size(91, 17);
			this->checkBox_ControlPlayer->TabIndex = 9;
			this->checkBox_ControlPlayer->Text = L"Control Player";
			this->checkBox_ControlPlayer->UseVisualStyleBackColor = true;
			this->checkBox_ControlPlayer->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_ControlPlayer_CheckedChanged);
			// 
			// numericUpDown_SpeedHack
			// 
			this->numericUpDown_SpeedHack->Location = System::Drawing::Point(151, 12);
			this->numericUpDown_SpeedHack->Name = L"numericUpDown_SpeedHack";
			this->numericUpDown_SpeedHack->Size = System::Drawing::Size(54, 20);
			this->numericUpDown_SpeedHack->TabIndex = 8;
			// 
			// checkBox_CPUReducer
			// 
			this->checkBox_CPUReducer->AutoSize = true;
			this->checkBox_CPUReducer->Location = System::Drawing::Point(14, 61);
			this->checkBox_CPUReducer->Name = L"checkBox_CPUReducer";
			this->checkBox_CPUReducer->Size = System::Drawing::Size(92, 17);
			this->checkBox_CPUReducer->TabIndex = 7;
			this->checkBox_CPUReducer->Text = L"CPU Reducer";
			this->checkBox_CPUReducer->UseVisualStyleBackColor = true;
			this->checkBox_CPUReducer->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CPUReducer_CheckedChanged);
			// 
			// checkBox_NoClip
			// 
			this->checkBox_NoClip->AutoSize = true;
			this->checkBox_NoClip->Location = System::Drawing::Point(14, 38);
			this->checkBox_NoClip->Name = L"checkBox_NoClip";
			this->checkBox_NoClip->Size = System::Drawing::Size(123, 17);
			this->checkBox_NoClip->TabIndex = 6;
			this->checkBox_NoClip->Text = L"Walk Through Walls";
			this->checkBox_NoClip->UseVisualStyleBackColor = true;
			this->checkBox_NoClip->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_NoClip_CheckedChanged);
			// 
			// checkBox_SpeedHack
			// 
			this->checkBox_SpeedHack->AutoSize = true;
			this->checkBox_SpeedHack->Location = System::Drawing::Point(14, 15);
			this->checkBox_SpeedHack->Name = L"checkBox_SpeedHack";
			this->checkBox_SpeedHack->Size = System::Drawing::Size(111, 17);
			this->checkBox_SpeedHack->TabIndex = 5;
			this->checkBox_SpeedHack->Text = L"Movespeed Hack";
			this->checkBox_SpeedHack->UseVisualStyleBackColor = true;
			this->checkBox_SpeedHack->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_SpeedHack_CheckedChanged);
			// 
			// groupBox_Options
			// 
			this->groupBox_Options->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox_Options->Controls->Add(this->tabControl_PacketOptions);
			this->groupBox_Options->Location = System::Drawing::Point(517, 12);
			this->groupBox_Options->Name = L"groupBox_Options";
			this->groupBox_Options->Size = System::Drawing::Size(258, 346);
			this->groupBox_Options->TabIndex = 10;
			this->groupBox_Options->TabStop = false;
			this->groupBox_Options->Text = L"Options";
			// 
			// tabControl_PacketOptions
			// 
			this->tabControl_PacketOptions->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl_PacketOptions->Controls->Add(this->tabPage_SendTools);
			this->tabControl_PacketOptions->Controls->Add(this->tabPage_LogTools);
			this->tabControl_PacketOptions->Controls->Add(this->tabPage_Misc);
			this->tabControl_PacketOptions->Location = System::Drawing::Point(6, 17);
			this->tabControl_PacketOptions->Name = L"tabControl_PacketOptions";
			this->tabControl_PacketOptions->SelectedIndex = 0;
			this->tabControl_PacketOptions->Size = System::Drawing::Size(216, 315);
			this->tabControl_PacketOptions->TabIndex = 2;
			// 
			// tabPage_SendTools
			// 
			this->tabPage_SendTools->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage_SendTools->Controls->Add(this->textBox_SpamPacketDelay);
			this->tabPage_SendTools->Controls->Add(this->button2);
			this->tabPage_SendTools->Controls->Add(this->checkBox_SpamPacket);
			this->tabPage_SendTools->Controls->Add(this->textBox1);
			this->tabPage_SendTools->Location = System::Drawing::Point(4, 22);
			this->tabPage_SendTools->Name = L"tabPage_SendTools";
			this->tabPage_SendTools->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_SendTools->Size = System::Drawing::Size(208, 289);
			this->tabPage_SendTools->TabIndex = 0;
			this->tabPage_SendTools->Text = L"Send Tools";
			// 
			// textBox_SpamPacketDelay
			// 
			this->textBox_SpamPacketDelay->Location = System::Drawing::Point(6, 6);
			this->textBox_SpamPacketDelay->Name = L"textBox_SpamPacketDelay";
			this->textBox_SpamPacketDelay->Size = System::Drawing::Size(100, 20);
			this->textBox_SpamPacketDelay->TabIndex = 0;
			this->textBox_SpamPacketDelay->Text = L"Delay (milliseconds)";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(67, 263);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Use Skill";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			// 
			// checkBox_SpamPacket
			// 
			this->checkBox_SpamPacket->AutoSize = true;
			this->checkBox_SpamPacket->Location = System::Drawing::Point(112, 9);
			this->checkBox_SpamPacket->Name = L"checkBox_SpamPacket";
			this->checkBox_SpamPacket->Size = System::Drawing::Size(90, 17);
			this->checkBox_SpamPacket->TabIndex = 1;
			this->checkBox_SpamPacket->Text = L"Spam Packet";
			this->checkBox_SpamPacket->UseVisualStyleBackColor = true;
			this->checkBox_SpamPacket->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_SpamPacket_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(5, 264);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(58, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"Skill ID";
			this->textBox1->Visible = false;
			// 
			// tabPage_LogTools
			// 
			this->tabPage_LogTools->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage_LogTools->Controls->Add(this->checkBox_HookRecv);
			this->tabPage_LogTools->Controls->Add(this->button_BlockPacket);
			this->tabPage_LogTools->Controls->Add(this->button_IgnorePacket);
			this->tabPage_LogTools->Controls->Add(this->listView_PacketRules);
			this->tabPage_LogTools->Controls->Add(this->button_ModifyPacket);
			this->tabPage_LogTools->Controls->Add(this->textBox_PacketRule2);
			this->tabPage_LogTools->Controls->Add(this->textBox_PacketRule1);
			this->tabPage_LogTools->Controls->Add(this->checkBox_HookSend);
			this->tabPage_LogTools->Location = System::Drawing::Point(4, 22);
			this->tabPage_LogTools->Name = L"tabPage_LogTools";
			this->tabPage_LogTools->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_LogTools->Size = System::Drawing::Size(208, 289);
			this->tabPage_LogTools->TabIndex = 1;
			this->tabPage_LogTools->Text = L"Log Tools";
			// 
			// checkBox_HookRecv
			// 
			this->checkBox_HookRecv->AutoSize = true;
			this->checkBox_HookRecv->Location = System::Drawing::Point(90, 6);
			this->checkBox_HookRecv->Name = L"checkBox_HookRecv";
			this->checkBox_HookRecv->Size = System::Drawing::Size(81, 17);
			this->checkBox_HookRecv->TabIndex = 11;
			this->checkBox_HookRecv->Text = L"Hook Recv";
			this->checkBox_HookRecv->UseVisualStyleBackColor = true;
			// 
			// button_BlockPacket
			// 
			this->button_BlockPacket->Location = System::Drawing::Point(6, 268);
			this->button_BlockPacket->Name = L"button_BlockPacket";
			this->button_BlockPacket->Size = System::Drawing::Size(70, 20);
			this->button_BlockPacket->TabIndex = 10;
			this->button_BlockPacket->Text = L"Block";
			this->button_BlockPacket->UseVisualStyleBackColor = true;
			// 
			// button_IgnorePacket
			// 
			this->button_IgnorePacket->Location = System::Drawing::Point(77, 268);
			this->button_IgnorePacket->Name = L"button_IgnorePacket";
			this->button_IgnorePacket->Size = System::Drawing::Size(66, 20);
			this->button_IgnorePacket->TabIndex = 9;
			this->button_IgnorePacket->Text = L"Ignore";
			this->button_IgnorePacket->UseVisualStyleBackColor = true;
			// 
			// listView_PacketRules
			// 
			this->listView_PacketRules->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->columnHeader_PacketRules,
					this->columnHeader_PacketRulesData
			});
			this->listView_PacketRules->FullRowSelect = true;
			this->listView_PacketRules->GridLines = true;
			this->listView_PacketRules->Location = System::Drawing::Point(6, 29);
			this->listView_PacketRules->Name = L"listView_PacketRules";
			this->listView_PacketRules->Size = System::Drawing::Size(226, 185);
			this->listView_PacketRules->TabIndex = 8;
			this->listView_PacketRules->UseCompatibleStateImageBehavior = false;
			this->listView_PacketRules->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader_PacketRules
			// 
			this->columnHeader_PacketRules->Text = L"Rule";
			// 
			// columnHeader_PacketRulesData
			// 
			this->columnHeader_PacketRulesData->Text = L"Packet/Opcode";
			this->columnHeader_PacketRulesData->Width = 148;
			// 
			// button_ModifyPacket
			// 
			this->button_ModifyPacket->Location = System::Drawing::Point(145, 267);
			this->button_ModifyPacket->Name = L"button_ModifyPacket";
			this->button_ModifyPacket->Size = System::Drawing::Size(57, 20);
			this->button_ModifyPacket->TabIndex = 7;
			this->button_ModifyPacket->Text = L"Modify";
			this->button_ModifyPacket->UseVisualStyleBackColor = true;
			// 
			// textBox_PacketRule2
			// 
			this->textBox_PacketRule2->Location = System::Drawing::Point(7, 246);
			this->textBox_PacketRule2->Name = L"textBox_PacketRule2";
			this->textBox_PacketRule2->Size = System::Drawing::Size(225, 20);
			this->textBox_PacketRule2->TabIndex = 5;
			this->textBox_PacketRule2->Text = L"Replacement (Modify)";
			// 
			// textBox_PacketRule1
			// 
			this->textBox_PacketRule1->Location = System::Drawing::Point(7, 220);
			this->textBox_PacketRule1->Name = L"textBox_PacketRule1";
			this->textBox_PacketRule1->Size = System::Drawing::Size(225, 20);
			this->textBox_PacketRule1->TabIndex = 4;
			this->textBox_PacketRule1->Text = L"Pattern (\?\? = wildcard)";
			// 
			// checkBox_HookSend
			// 
			this->checkBox_HookSend->AutoSize = true;
			this->checkBox_HookSend->Location = System::Drawing::Point(7, 7);
			this->checkBox_HookSend->Name = L"checkBox_HookSend";
			this->checkBox_HookSend->Size = System::Drawing::Size(80, 17);
			this->checkBox_HookSend->TabIndex = 3;
			this->checkBox_HookSend->Text = L"Hook Send";
			this->checkBox_HookSend->UseVisualStyleBackColor = true;
			this->checkBox_HookSend->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_HookSend_CheckedChanged);
			// 
			// tabPage_Misc
			// 
			this->tabPage_Misc->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage_Misc->Controls->Add(this->groupBox4);
			this->tabPage_Misc->Controls->Add(this->groupBox_AutoLogin);
			this->tabPage_Misc->Controls->Add(this->groupBox2);
			this->tabPage_Misc->Controls->Add(this->button1);
			this->tabPage_Misc->Location = System::Drawing::Point(4, 22);
			this->tabPage_Misc->Name = L"tabPage_Misc";
			this->tabPage_Misc->Size = System::Drawing::Size(208, 289);
			this->tabPage_Misc->TabIndex = 2;
			this->tabPage_Misc->Text = L"Misc.";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label1);
			this->groupBox4->Controls->Add(this->numericUpDown_DungeonMultiplier);
			this->groupBox4->Controls->Add(this->checkBox_SilverFarmBot);
			this->groupBox4->Location = System::Drawing::Point(3, 223);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(229, 71);
			this->groupBox4->TabIndex = 11;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Silver farm bot";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(70, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Multiplier";
			// 
			// numericUpDown_DungeonMultiplier
			// 
			this->numericUpDown_DungeonMultiplier->Location = System::Drawing::Point(6, 42);
			this->numericUpDown_DungeonMultiplier->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {
				System::Int32::MinValue,
					0, 0, 0
			});
			this->numericUpDown_DungeonMultiplier->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, System::Int32::MinValue });
			this->numericUpDown_DungeonMultiplier->Name = L"numericUpDown_DungeonMultiplier";
			this->numericUpDown_DungeonMultiplier->Size = System::Drawing::Size(59, 20);
			this->numericUpDown_DungeonMultiplier->TabIndex = 1;
			// 
			// checkBox_SilverFarmBot
			// 
			this->checkBox_SilverFarmBot->AutoSize = true;
			this->checkBox_SilverFarmBot->Location = System::Drawing::Point(7, 21);
			this->checkBox_SilverFarmBot->Name = L"checkBox_SilverFarmBot";
			this->checkBox_SilverFarmBot->Size = System::Drawing::Size(59, 17);
			this->checkBox_SilverFarmBot->TabIndex = 0;
			this->checkBox_SilverFarmBot->Text = L"Enable";
			this->checkBox_SilverFarmBot->UseVisualStyleBackColor = true;
			// 
			// groupBox_AutoLogin
			// 
			this->groupBox_AutoLogin->Controls->Add(this->checkBox_AutoLogin);
			this->groupBox_AutoLogin->Controls->Add(this->label_CharIndex);
			this->groupBox_AutoLogin->Controls->Add(this->label_Channel);
			this->groupBox_AutoLogin->Controls->Add(this->numericUpDown_CharID);
			this->groupBox_AutoLogin->Controls->Add(this->numericUpDown_ChannelID);
			this->groupBox_AutoLogin->Location = System::Drawing::Point(3, 119);
			this->groupBox_AutoLogin->Name = L"groupBox_AutoLogin";
			this->groupBox_AutoLogin->Size = System::Drawing::Size(202, 101);
			this->groupBox_AutoLogin->TabIndex = 10;
			this->groupBox_AutoLogin->TabStop = false;
			this->groupBox_AutoLogin->Text = L"Auto-Login";
			// 
			// checkBox_AutoLogin
			// 
			this->checkBox_AutoLogin->AutoSize = true;
			this->checkBox_AutoLogin->Location = System::Drawing::Point(6, 72);
			this->checkBox_AutoLogin->Name = L"checkBox_AutoLogin";
			this->checkBox_AutoLogin->Size = System::Drawing::Size(59, 17);
			this->checkBox_AutoLogin->TabIndex = 4;
			this->checkBox_AutoLogin->Text = L"Enable";
			this->checkBox_AutoLogin->UseVisualStyleBackColor = true;
			// 
			// label_CharIndex
			// 
			this->label_CharIndex->AutoSize = true;
			this->label_CharIndex->Location = System::Drawing::Point(73, 48);
			this->label_CharIndex->Name = L"label_CharIndex";
			this->label_CharIndex->Size = System::Drawing::Size(58, 13);
			this->label_CharIndex->TabIndex = 3;
			this->label_CharIndex->Text = L"Char Index";
			// 
			// label_Channel
			// 
			this->label_Channel->AutoSize = true;
			this->label_Channel->Location = System::Drawing::Point(73, 20);
			this->label_Channel->Name = L"label_Channel";
			this->label_Channel->Size = System::Drawing::Size(46, 13);
			this->label_Channel->TabIndex = 2;
			this->label_Channel->Text = L"Channel";
			// 
			// numericUpDown_CharID
			// 
			this->numericUpDown_CharID->Location = System::Drawing::Point(6, 46);
			this->numericUpDown_CharID->Name = L"numericUpDown_CharID";
			this->numericUpDown_CharID->Size = System::Drawing::Size(61, 20);
			this->numericUpDown_CharID->TabIndex = 1;
			// 
			// numericUpDown_ChannelID
			// 
			this->numericUpDown_ChannelID->Location = System::Drawing::Point(6, 18);
			this->numericUpDown_ChannelID->Name = L"numericUpDown_ChannelID";
			this->numericUpDown_ChannelID->Size = System::Drawing::Size(61, 20);
			this->numericUpDown_ChannelID->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->textBox11);
			this->groupBox2->Controls->Add(this->textBox10);
			this->groupBox2->Controls->Add(this->textBox9);
			this->groupBox2->Controls->Add(this->label_PosX);
			this->groupBox2->Controls->Add(this->label_PosY);
			this->groupBox2->Controls->Add(this->label_PosZ);
			this->groupBox2->Location = System::Drawing::Point(3, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(205, 119);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Coord Hacks";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(6, 88);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(196, 22);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Teleport";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(126, 62);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(76, 20);
			this->textBox11->TabIndex = 5;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(126, 37);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(76, 20);
			this->textBox10->TabIndex = 4;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(126, 12);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(76, 20);
			this->textBox9->TabIndex = 3;
			// 
			// label_PosX
			// 
			this->label_PosX->AutoSize = true;
			this->label_PosX->Location = System::Drawing::Point(8, 19);
			this->label_PosX->Name = L"label_PosX";
			this->label_PosX->Size = System::Drawing::Size(20, 13);
			this->label_PosX->TabIndex = 0;
			this->label_PosX->Text = L"X: ";
			// 
			// label_PosY
			// 
			this->label_PosY->AutoSize = true;
			this->label_PosY->Location = System::Drawing::Point(8, 42);
			this->label_PosY->Name = L"label_PosY";
			this->label_PosY->Size = System::Drawing::Size(20, 13);
			this->label_PosY->TabIndex = 1;
			this->label_PosY->Text = L"Y: ";
			// 
			// label_PosZ
			// 
			this->label_PosZ->AutoSize = true;
			this->label_PosZ->Location = System::Drawing::Point(8, 65);
			this->label_PosZ->Name = L"label_PosZ";
			this->label_PosZ->Size = System::Drawing::Size(20, 13);
			this->label_PosZ->TabIndex = 2;
			this->label_PosZ->Text = L"Z: ";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(150, 88);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(8, 8);
			this->button1->TabIndex = 7;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(751, 349);
			this->Controls->Add(this->groupBox_Options);
			this->Controls->Add(this->tabControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"DragonNest Bot (BR)";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->contextMenuStrip_LogPackets->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_SpeedHack))->EndInit();
			this->groupBox_Options->ResumeLayout(false);
			this->tabControl_PacketOptions->ResumeLayout(false);
			this->tabPage_SendTools->ResumeLayout(false);
			this->tabPage_SendTools->PerformLayout();
			this->tabPage_LogTools->ResumeLayout(false);
			this->tabPage_LogTools->PerformLayout();
			this->tabPage_Misc->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_DungeonMultiplier))->EndInit();
			this->groupBox_AutoLogin->ResumeLayout(false);
			this->groupBox_AutoLogin->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CharID))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_ChannelID))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

public: System::Void ProcessSendQueue() {

	while (this->checkBox_HookSend->Checked == TRUE) {

		if (SendPacketQueue.size() > 0) {

			PacketWriter* sendPacket = SendPacketQueue.front();

			wchar_t *pwDataText;
			wchar_t pwLengthText[10];

			CHAR* packetString = convertPacketFormatToString((unsigned char*)sendPacket->GetBuffer(), sendPacket->GetSize());

			DWORD dwNum = MultiByteToWideChar(CP_UTF8, 0, packetString, -1, NULL, 0);
			_itow_s(sendPacket->GetSize(), pwLengthText, 10);

			pwDataText = new wchar_t[dwNum];
			MultiByteToWideChar(CP_UTF8, 0, packetString, -1, pwDataText, dwNum);

			String ^dataString = gcnew String(pwDataText);
			String ^lengthString = gcnew String(pwLengthText);

			array<String^>^ subItems = gcnew array<String^>(2);
			subItems[0] = gcnew String(lengthString);
			subItems[1] = gcnew String(dataString);

			ListViewItem^ itm = gcnew ListViewItem(subItems);
			this->listView_PacketLog->Items->Add(itm);

			SendPacketQueue.pop();
			delete sendPacket;
			delete[] pwDataText;
			free(packetString);
		}
		else
			Thread::Sleep(300);
	}
}

private: System::Void UpdateCharacterInfo()
{
	while (1)
	{
		FLOAT X = ReadPointer<FLOAT>(dwActorBase, dwOfsCharX);
		FLOAT Y = ReadPointer<FLOAT>(dwActorBase, dwOfsCharY);
		FLOAT Z = ReadPointer<FLOAT>(dwActorBase, dwOfsCharZ);
		char arr[10];
		sprintf(arr, "%f", X);
		String^ strX = gcnew String(arr);
		sprintf(arr, "%f", Y);
		String^ strY = gcnew String(arr);
		sprintf(arr, "%f", Z);
		String^ strZ = gcnew String(arr);

		this->label_PosX->Text = "X: " + strX;
		this->label_PosY->Text = "Y: " + strY;
		this->label_PosZ->Text = "Z: " + strZ;

		Sleep(300);
	}
}

private: System::Void button_SendPacket_Click(System::Object^  sender, System::EventArgs^  e) {

	String^ Pocket = gcnew String(this->textBox_SendPacket->Text);
	char* string_packet = (char*)(void*)Marshal::StringToHGlobalAnsi(Pocket);
	BYTE* Packet = convertStringToPacketFormat(string_packet);
	SendVillagePacket(sendClass, Packet[0], Packet[1], Packet, getPacketLength(string_packet) - 2);

}
private: System::Void checkBox_HookSend_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_HookSend->Checked == TRUE)
	{
		WriteHookBytes(hkVillageSendPacket, SendHook, TRUE);
		SendLogThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::ProcessSendQueue));
		SendLogThread->Start();
	}
	else
	{
		WriteHookBytes(hkVillageSendPacket, SendHook, FALSE);
	}

}
private: System::Void checkBox_NoClip_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_NoClip->Checked == TRUE)
	{
		WriteHackBytes(hNoclip, TRUE);
	}
	else
	{
		WriteHackBytes(hNoclip, TRUE);
	}
}
private: System::Void checkBox_SpeedHack_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_SpeedHack->Checked == TRUE)
	{
		WriteHookBytes(hkSpeedHack, MovespeedHook, TRUE);
	}
	else
	{
		WriteHookBytes(hkSpeedHack, MovespeedHook, FALSE);
	}

}
private: System::Void checkBox_CPUReducer_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_CPUReducer->Checked == TRUE)
	{
		WriteHookBytes(hkCPUReducer, CPUReducerHook, TRUE);
	}
	else
	{
		WriteHookBytes(hkCPUReducer, CPUReducerHook, FALSE);
	}
}
private: System::Void checkBox_ControlPlayer_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void copySendPacket() {

	ListViewItem^ selectedItem;

	for (int i = 0; i < listView_PacketLog->Items->Count; i++) {
		selectedItem = listView_PacketLog->Items[i];
		if (selectedItem->Selected == true) {
			String^ packetString = selectedItem->SubItems[1]->Text;
			Clipboard::SetDataObject(packetString, true);
		}
	}
}

private: System::Void copySelectedToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Thread^ newThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::copySendPacket));
	newThread->SetApartmentState(System::Threading::ApartmentState::STA);
	newThread->Start();
}

private: System::Void clearLogToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->listView_PacketLog->Items->Clear();
}
private: System::Void checkBox_RamReducer_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_RamReducer->Checked == TRUE)
	{

	}
	else
	{

	}
}

private: void SpamPacket() {

	String^ delayTime = gcnew String(this->textBox_SpamPacketDelay->Text);
	char* ascii_delay = (char*)(void*)Marshal::StringToHGlobalAnsi(delayTime);
	int sleepTime = atoi(ascii_delay);

	while (this->checkBox_SpamPacket->Checked == TRUE) {
		String^ packetToSend = textBox_SendPacket->Text;
		char* ascii_multi_packets = (char*)(void*)Marshal::StringToHGlobalAnsi(packetToSend);
		BYTE* packet = convertStringToPacketFormat(ascii_multi_packets);
		SendVillagePacket(0, packet[0], packet[1], packet, getPacketLength(ascii_multi_packets));
		Sleep(sleepTime);
	}
}

private: System::Void checkBox_SpamPacket_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_SpamPacket->Checked == TRUE)
	{
		SpamPacketThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::SpamPacket));
		SpamPacketThread->Start();
	}
	else
	{
		SpamPacketThread->Abort();
	}
}
private: System::Void checkBox_NoDelayPetLoot_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (this->checkBox_NoDelayPetLoot->Checked == TRUE)
	{
		WriteHackBytes(hInstantPetLoot, TRUE);
	}
	else
	{
		WriteHackBytes(hInstantPetLoot, FALSE);
	}
}
private: System::Void button_RunScript_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ scriptText = this->textBox_ScriptText->Text;
	char* scriptBuffer = (char*)(void*)Marshal::StringToHGlobalAnsi(scriptText);
	ScriptThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&execute_lua, (LPVOID)scriptBuffer, 0, 0);
}
private: System::Void button_EndScript_Click(System::Object^  sender, System::EventArgs^  e) {
	end_lua();
}
};
}
