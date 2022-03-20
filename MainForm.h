#pragma
#include <iostream>
#include "lib/Menu.hpp"


using namespace std;
namespace MainForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MineHati;


	/// <summary>
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	private:
		 
	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ InvPanel;
	protected:
	private: System::Windows::Forms::CheckBox^ InvSlot1;
	private: System::Windows::Forms::CheckBox^ InvSlot3;
	private: System::Windows::Forms::CheckBox^ InvSlot2;
	private: System::Windows::Forms::CheckBox^ InvSlot4;
	private: System::Windows::Forms::CheckBox^ InvSlot5;
	private: System::Windows::Forms::CheckBox^ InvSlot6;
	private: System::Windows::Forms::CheckBox^ InvSlot7;
	private: System::Windows::Forms::CheckBox^ InvSlot8;
	private: System::Windows::Forms::CheckBox^ InvSlot9;
	private: System::Windows::Forms::CheckBox^ InvSlot25;
	private: System::Windows::Forms::CheckBox^ InvSlot26;
	private: System::Windows::Forms::CheckBox^ InvSlot27;
	private: System::Windows::Forms::CheckBox^ InvSlot22;
	private: System::Windows::Forms::CheckBox^ InvSlot23;
	private: System::Windows::Forms::CheckBox^ InvSlot24;
	private: System::Windows::Forms::CheckBox^ InvSlot21;
	private: System::Windows::Forms::CheckBox^ InvSlot20;
	private: System::Windows::Forms::CheckBox^ InvSlot19;
	private: System::Windows::Forms::CheckBox^ InvSlot16;
	private: System::Windows::Forms::CheckBox^ InvSlot17;
	private: System::Windows::Forms::CheckBox^ InvSlot18;
	private: System::Windows::Forms::CheckBox^ InvSlot13;
	private: System::Windows::Forms::CheckBox^ InvSlot14;
	private: System::Windows::Forms::CheckBox^ InvSlot15;
	private: System::Windows::Forms::CheckBox^ InvSlot12;
	private: System::Windows::Forms::CheckBox^ InvSlot11;
	private: System::Windows::Forms::CheckBox^ InvSlot10;
	private: System::Windows::Forms::TextBox^ ConsoleBox;
	private: System::Windows::Forms::TextBox^ InputBox;

	private: System::Windows::Forms::Panel^ CraftPanel;
	private: System::Windows::Forms::CheckBox^ CraftSlot9;
	private: System::Windows::Forms::CheckBox^ CraftSlot8;

	private: System::Windows::Forms::CheckBox^ CraftSlot7;

	private: System::Windows::Forms::CheckBox^ CraftSlot6;

	private: System::Windows::Forms::CheckBox^ CraftSlot5;

	private: System::Windows::Forms::CheckBox^ CraftSlot4;

	private: System::Windows::Forms::CheckBox^ CraftSlot3;

	private: System::Windows::Forms::CheckBox^ CraftSlot2;

	private: System::Windows::Forms::CheckBox^ CraftSlot1;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ GiveButton;
	private: System::Windows::Forms::Button^ CraftButton;
	private: System::Windows::Forms::NumericUpDown^ GiveQty;
	private: System::Windows::Forms::TextBox^ GiveInput;
	private: System::Windows::Forms::Label^ InventoryLabel;
	private: System::Windows::Forms::Label^ CraftingLabel;
	private: System::Windows::Forms::Label^ GiveLabel;
	private: System::Windows::Forms::Label^ CommandTooltip;

	private: System::Windows::Forms::Button^ ExecuteButton;
	private: System::Windows::Forms::Label^ DiscardTooltip;
	private: System::Windows::Forms::Button^ DiscardButton;
	private: System::Windows::Forms::Label^ DiscardLabel;
	private: System::Windows::Forms::Label^ UseTooltip;
	private: System::Windows::Forms::Button^ UseButton;
	private: System::Windows::Forms::Label^ UseLabel;
	private: System::Windows::Forms::Label^ MoveTooltip;
	private: System::Windows::Forms::Button^ MoveButton;
	private: System::Windows::Forms::Label^ MoveLabel;
	private: System::Windows::Forms::SaveFileDialog^ SaveExport;

	private: System::Windows::Forms::Button^ ExportButton;
	private: System::Windows::Forms::ErrorProvider^ ExceptionProvider;
	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->InvPanel = (gcnew System::Windows::Forms::Panel());
			this->InventoryLabel = (gcnew System::Windows::Forms::Label());
			this->InvSlot25 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot26 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot27 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot22 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot23 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot24 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot21 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot20 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot19 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot16 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot17 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot18 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot13 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot14 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot15 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot12 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot11 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot10 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot7 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot8 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot9 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot4 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot5 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot6 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot3 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot2 = (gcnew System::Windows::Forms::CheckBox());
			this->InvSlot1 = (gcnew System::Windows::Forms::CheckBox());
			this->ConsoleBox = (gcnew System::Windows::Forms::TextBox());
			this->InputBox = (gcnew System::Windows::Forms::TextBox());
			this->CraftPanel = (gcnew System::Windows::Forms::Panel());
			this->CraftSlot9 = (gcnew System::Windows::Forms::CheckBox());
			this->CraftSlot8 = (gcnew System::Windows::Forms::CheckBox());
			this->CraftSlot7 = (gcnew System::Windows::Forms::CheckBox());
			this->CraftSlot6 = (gcnew System::Windows::Forms::CheckBox());
			this->CraftSlot5 = (gcnew System::Windows::Forms::CheckBox());
			this->CraftSlot4 = (gcnew System::Windows::Forms::CheckBox());
			this->CraftSlot3 = (gcnew System::Windows::Forms::CheckBox());
			this->CraftSlot2 = (gcnew System::Windows::Forms::CheckBox());
			this->CraftSlot1 = (gcnew System::Windows::Forms::CheckBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->ExportButton = (gcnew System::Windows::Forms::Button());
			this->UseTooltip = (gcnew System::Windows::Forms::Label());
			this->UseButton = (gcnew System::Windows::Forms::Button());
			this->UseLabel = (gcnew System::Windows::Forms::Label());
			this->MoveTooltip = (gcnew System::Windows::Forms::Label());
			this->MoveButton = (gcnew System::Windows::Forms::Button());
			this->MoveLabel = (gcnew System::Windows::Forms::Label());
			this->DiscardTooltip = (gcnew System::Windows::Forms::Label());
			this->DiscardButton = (gcnew System::Windows::Forms::Button());
			this->DiscardLabel = (gcnew System::Windows::Forms::Label());
			this->CommandTooltip = (gcnew System::Windows::Forms::Label());
			this->GiveLabel = (gcnew System::Windows::Forms::Label());
			this->CraftButton = (gcnew System::Windows::Forms::Button());
			this->GiveQty = (gcnew System::Windows::Forms::NumericUpDown());
			this->GiveInput = (gcnew System::Windows::Forms::TextBox());
			this->GiveButton = (gcnew System::Windows::Forms::Button());
			this->CraftingLabel = (gcnew System::Windows::Forms::Label());
			this->ExecuteButton = (gcnew System::Windows::Forms::Button());
			this->SaveExport = (gcnew System::Windows::Forms::SaveFileDialog());
			this->ExceptionProvider = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->InvPanel->SuspendLayout();
			this->CraftPanel->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GiveQty))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ExceptionProvider))->BeginInit();
			this->SuspendLayout();
			//
			// InvPanel
			//
			this->InvPanel->Controls->Add(this->InventoryLabel);
			this->InvPanel->Controls->Add(this->InvSlot25);
			this->InvPanel->Controls->Add(this->InvSlot26);
			this->InvPanel->Controls->Add(this->InvSlot27);
			this->InvPanel->Controls->Add(this->InvSlot22);
			this->InvPanel->Controls->Add(this->InvSlot23);
			this->InvPanel->Controls->Add(this->InvSlot24);
			this->InvPanel->Controls->Add(this->InvSlot21);
			this->InvPanel->Controls->Add(this->InvSlot20);
			this->InvPanel->Controls->Add(this->InvSlot19);
			this->InvPanel->Controls->Add(this->InvSlot16);
			this->InvPanel->Controls->Add(this->InvSlot17);
			this->InvPanel->Controls->Add(this->InvSlot18);
			this->InvPanel->Controls->Add(this->InvSlot13);
			this->InvPanel->Controls->Add(this->InvSlot14);
			this->InvPanel->Controls->Add(this->InvSlot15);
			this->InvPanel->Controls->Add(this->InvSlot12);
			this->InvPanel->Controls->Add(this->InvSlot11);
			this->InvPanel->Controls->Add(this->InvSlot10);
			this->InvPanel->Controls->Add(this->InvSlot7);
			this->InvPanel->Controls->Add(this->InvSlot8);
			this->InvPanel->Controls->Add(this->InvSlot9);
			this->InvPanel->Controls->Add(this->InvSlot4);
			this->InvPanel->Controls->Add(this->InvSlot5);
			this->InvPanel->Controls->Add(this->InvSlot6);
			this->InvPanel->Controls->Add(this->InvSlot3);
			this->InvPanel->Controls->Add(this->InvSlot2);
			this->InvPanel->Controls->Add(this->InvSlot1);
			this->InvPanel->Location = System::Drawing::Point(16, 226);
			this->InvPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvPanel->Name = L"InvPanel";
			this->InvPanel->Size = System::Drawing::Size(1147, 211);
			this->InvPanel->TabIndex = 1;
			//
			// InventoryLabel
			//
			this->InventoryLabel->AutoSize = true;
			this->InventoryLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InventoryLabel->Location = System::Drawing::Point(3, -3);
			this->InventoryLabel->Name = L"InventoryLabel";
			this->InventoryLabel->Size = System::Drawing::Size(101, 25);
			this->InventoryLabel->TabIndex = 7;
			this->InventoryLabel->Text = L"Inventory";
			//
			// InvSlot25
			//
			this->InvSlot25->AutoSize = true;
			this->InvSlot25->Location = System::Drawing::Point(764, 144);
			this->InvSlot25->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot25->Name = L"InvSlot25";
			this->InvSlot25->Size = System::Drawing::Size(115, 55);
			this->InvSlot25->TabIndex = 26;
			this->InvSlot25->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot25->UseVisualStyleBackColor = true;
			//
			// InvSlot26
			//
			this->InvSlot26->AutoSize = true;
			this->InvSlot26->Location = System::Drawing::Point(889, 144);
			this->InvSlot26->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot26->Name = L"InvSlot26";
			this->InvSlot26->Size = System::Drawing::Size(115, 55);
			this->InvSlot26->TabIndex = 25;
			this->InvSlot26->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot26->UseVisualStyleBackColor = true;
			//
			// InvSlot27
			//
			this->InvSlot27->AutoSize = true;
			this->InvSlot27->Location = System::Drawing::Point(1015, 144);
			this->InvSlot27->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot27->Name = L"InvSlot27";
			this->InvSlot27->Size = System::Drawing::Size(115, 55);
			this->InvSlot27->TabIndex = 24;
			this->InvSlot27->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot27->UseVisualStyleBackColor = true;
			//
			// InvSlot22
			//
			this->InvSlot22->AutoSize = true;
			this->InvSlot22->Location = System::Drawing::Point(388, 144);
			this->InvSlot22->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot22->Name = L"InvSlot22";
			this->InvSlot22->Size = System::Drawing::Size(115, 55);
			this->InvSlot22->TabIndex = 23;
			this->InvSlot22->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot22->UseVisualStyleBackColor = true;
			//
			// InvSlot23
			//
			this->InvSlot23->AutoSize = true;
			this->InvSlot23->Location = System::Drawing::Point(513, 144);
			this->InvSlot23->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot23->Name = L"InvSlot23";
			this->InvSlot23->Size = System::Drawing::Size(115, 55);
			this->InvSlot23->TabIndex = 22;
			this->InvSlot23->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot23->UseVisualStyleBackColor = true;
			//
			// InvSlot24
			//
			this->InvSlot24->AutoSize = true;
			this->InvSlot24->Location = System::Drawing::Point(639, 144);
			this->InvSlot24->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot24->Name = L"InvSlot24";
			this->InvSlot24->Size = System::Drawing::Size(115, 55);
			this->InvSlot24->TabIndex = 21;
			this->InvSlot24->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot24->UseVisualStyleBackColor = true;
			//
			// InvSlot21
			//
			this->InvSlot21->AutoSize = true;
			this->InvSlot21->Location = System::Drawing::Point(263, 144);
			this->InvSlot21->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot21->Name = L"InvSlot21";
			this->InvSlot21->Size = System::Drawing::Size(115, 55);
			this->InvSlot21->TabIndex = 20;
			this->InvSlot21->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot21->UseVisualStyleBackColor = true;
			//
			// InvSlot20
			//
			this->InvSlot20->AutoSize = true;
			this->InvSlot20->Location = System::Drawing::Point(137, 144);
			this->InvSlot20->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot20->Name = L"InvSlot20";
			this->InvSlot20->Size = System::Drawing::Size(115, 55);
			this->InvSlot20->TabIndex = 19;
			this->InvSlot20->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot20->UseVisualStyleBackColor = true;
			//
			// InvSlot19
			//
			this->InvSlot19->AutoSize = true;
			this->InvSlot19->Location = System::Drawing::Point(12, 144);
			this->InvSlot19->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot19->Name = L"InvSlot19";
			this->InvSlot19->Size = System::Drawing::Size(115, 55);
			this->InvSlot19->TabIndex = 18;
			this->InvSlot19->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot19->UseVisualStyleBackColor = true;
			//
			// InvSlot16
			//
			this->InvSlot16->AutoSize = true;
			this->InvSlot16->Location = System::Drawing::Point(764, 86);
			this->InvSlot16->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot16->Name = L"InvSlot16";
			this->InvSlot16->Size = System::Drawing::Size(115, 55);
			this->InvSlot16->TabIndex = 17;
			this->InvSlot16->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot16->UseVisualStyleBackColor = true;
			//
			// InvSlot17
			//
			this->InvSlot17->AutoSize = true;
			this->InvSlot17->Location = System::Drawing::Point(889, 86);
			this->InvSlot17->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot17->Name = L"InvSlot17";
			this->InvSlot17->Size = System::Drawing::Size(115, 55);
			this->InvSlot17->TabIndex = 16;
			this->InvSlot17->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot17->UseVisualStyleBackColor = true;
			//
			// InvSlot18
			//
			this->InvSlot18->AutoSize = true;
			this->InvSlot18->Location = System::Drawing::Point(1015, 86);
			this->InvSlot18->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot18->Name = L"InvSlot18";
			this->InvSlot18->Size = System::Drawing::Size(115, 55);
			this->InvSlot18->TabIndex = 15;
			this->InvSlot18->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot18->UseVisualStyleBackColor = true;
			//
			// InvSlot13
			//
			this->InvSlot13->AutoSize = true;
			this->InvSlot13->Location = System::Drawing::Point(388, 86);
			this->InvSlot13->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot13->Name = L"InvSlot13";
			this->InvSlot13->Size = System::Drawing::Size(115, 55);
			this->InvSlot13->TabIndex = 14;
			this->InvSlot13->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot13->UseVisualStyleBackColor = true;
			//
			// InvSlot14
			//
			this->InvSlot14->AutoSize = true;
			this->InvSlot14->Location = System::Drawing::Point(513, 86);
			this->InvSlot14->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot14->Name = L"InvSlot14";
			this->InvSlot14->Size = System::Drawing::Size(115, 55);
			this->InvSlot14->TabIndex = 13;
			this->InvSlot14->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot14->UseVisualStyleBackColor = true;
			//
			// InvSlot15
			//
			this->InvSlot15->AutoSize = true;
			this->InvSlot15->Location = System::Drawing::Point(639, 86);
			this->InvSlot15->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot15->Name = L"InvSlot15";
			this->InvSlot15->Size = System::Drawing::Size(115, 55);
			this->InvSlot15->TabIndex = 12;
			this->InvSlot15->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot15->UseVisualStyleBackColor = true;
			//
			// InvSlot12
			//
			this->InvSlot12->AutoSize = true;
			this->InvSlot12->Location = System::Drawing::Point(263, 86);
			this->InvSlot12->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot12->Name = L"InvSlot12";
			this->InvSlot12->Size = System::Drawing::Size(115, 55);
			this->InvSlot12->TabIndex = 11;
			this->InvSlot12->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot12->UseVisualStyleBackColor = true;
			//
			// InvSlot11
			//
			this->InvSlot11->AutoSize = true;
			this->InvSlot11->Location = System::Drawing::Point(137, 86);
			this->InvSlot11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot11->Name = L"InvSlot11";
			this->InvSlot11->Size = System::Drawing::Size(115, 55);
			this->InvSlot11->TabIndex = 10;
			this->InvSlot11->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot11->UseVisualStyleBackColor = true;
			//
			// InvSlot10
			//
			this->InvSlot10->AutoSize = true;
			this->InvSlot10->Location = System::Drawing::Point(12, 86);
			this->InvSlot10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot10->Name = L"InvSlot10";
			this->InvSlot10->Size = System::Drawing::Size(115, 55);
			this->InvSlot10->TabIndex = 9;
			this->InvSlot10->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot10->UseVisualStyleBackColor = true;
			//
			// InvSlot7
			//
			this->InvSlot7->AutoSize = true;
			this->InvSlot7->Location = System::Drawing::Point(764, 28);
			this->InvSlot7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot7->Name = L"InvSlot7";
			this->InvSlot7->Size = System::Drawing::Size(115, 55);
			this->InvSlot7->TabIndex = 8;
			this->InvSlot7->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot7->UseVisualStyleBackColor = true;
			//
			// InvSlot8
			//
			this->InvSlot8->AutoSize = true;
			this->InvSlot8->Location = System::Drawing::Point(889, 28);
			this->InvSlot8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot8->Name = L"InvSlot8";
			this->InvSlot8->Size = System::Drawing::Size(115, 55);
			this->InvSlot8->TabIndex = 7;
			this->InvSlot8->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot8->UseVisualStyleBackColor = true;
			//
			// InvSlot9
			//
			this->InvSlot9->AutoSize = true;
			this->InvSlot9->Location = System::Drawing::Point(1015, 28);
			this->InvSlot9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot9->Name = L"InvSlot9";
			this->InvSlot9->Size = System::Drawing::Size(115, 55);
			this->InvSlot9->TabIndex = 6;
			this->InvSlot9->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot9->UseVisualStyleBackColor = true;
			//
			// InvSlot4
			//
			this->InvSlot4->AutoSize = true;
			this->InvSlot4->Location = System::Drawing::Point(388, 28);
			this->InvSlot4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot4->Name = L"InvSlot4";
			this->InvSlot4->Size = System::Drawing::Size(115, 55);
			this->InvSlot4->TabIndex = 5;
			this->InvSlot4->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot4->UseVisualStyleBackColor = true;
			//
			// InvSlot5
			//
			this->InvSlot5->AutoSize = true;
			this->InvSlot5->Location = System::Drawing::Point(513, 28);
			this->InvSlot5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot5->Name = L"InvSlot5";
			this->InvSlot5->Size = System::Drawing::Size(115, 55);
			this->InvSlot5->TabIndex = 4;
			this->InvSlot5->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot5->UseVisualStyleBackColor = true;
			//
			// InvSlot6
			//
			this->InvSlot6->AutoSize = true;
			this->InvSlot6->Location = System::Drawing::Point(639, 28);
			this->InvSlot6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot6->Name = L"InvSlot6";
			this->InvSlot6->Size = System::Drawing::Size(115, 55);
			this->InvSlot6->TabIndex = 3;
			this->InvSlot6->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot6->UseVisualStyleBackColor = true;
			//
			// InvSlot3
			//
			this->InvSlot3->AutoSize = true;
			this->InvSlot3->Location = System::Drawing::Point(263, 28);
			this->InvSlot3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot3->Name = L"InvSlot3";
			this->InvSlot3->Size = System::Drawing::Size(115, 55);
			this->InvSlot3->TabIndex = 2;
			this->InvSlot3->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot3->UseVisualStyleBackColor = true;
			//
			// InvSlot2
			//
			this->InvSlot2->AutoSize = true;
			this->InvSlot2->Location = System::Drawing::Point(137, 28);
			this->InvSlot2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot2->Name = L"InvSlot2";
			this->InvSlot2->Size = System::Drawing::Size(115, 55);
			this->InvSlot2->TabIndex = 1;
			this->InvSlot2->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot2->UseVisualStyleBackColor = true;
			this->InvSlot2->CheckedChanged += gcnew System::EventHandler(this, &Form1::Slot_Click);
			//
			// InvSlot1
			//
			this->InvSlot1->AutoSize = true;
			this->InvSlot1->Location = System::Drawing::Point(12, 28);
			this->InvSlot1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InvSlot1->Name = L"InvSlot1";
			this->InvSlot1->Size = System::Drawing::Size(115, 55);
			this->InvSlot1->TabIndex = 0;
			this->InvSlot1->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->InvSlot1->UseVisualStyleBackColor = true;
			this->InvSlot1->CheckedChanged += gcnew System::EventHandler(this, &Form1::Slot_Click);
			//
			// ConsoleBox
			//
			this->ConsoleBox->Enabled = false;
			this->ConsoleBox->Location = System::Drawing::Point(15, 443);
			this->ConsoleBox->Margin = System::Windows::Forms::Padding(4);
			this->ConsoleBox->Multiline = true;
			this->ConsoleBox->Name = L"ConsoleBox";
			this->ConsoleBox->Size = System::Drawing::Size(1145, 102);
			this->ConsoleBox->TabIndex = 2;
			//
			// InputBox
			//
			this->InputBox->Location = System::Drawing::Point(16, 553);
			this->InputBox->Margin = System::Windows::Forms::Padding(4);
			this->InputBox->Multiline = true;
			this->InputBox->Name = L"InputBox";
			this->InputBox->Size = System::Drawing::Size(1004, 33);
			this->InputBox->TabIndex = 3;
			//
			// CraftPanel
			//
			this->CraftPanel->Controls->Add(this->CraftSlot9);
			this->CraftPanel->Controls->Add(this->CraftSlot8);
			this->CraftPanel->Controls->Add(this->CraftSlot7);
			this->CraftPanel->Controls->Add(this->CraftSlot6);
			this->CraftPanel->Controls->Add(this->CraftSlot5);
			this->CraftPanel->Controls->Add(this->CraftSlot4);
			this->CraftPanel->Controls->Add(this->CraftSlot3);
			this->CraftPanel->Controls->Add(this->CraftSlot2);
			this->CraftPanel->Controls->Add(this->CraftSlot1);
			this->CraftPanel->Location = System::Drawing::Point(16, 27);
			this->CraftPanel->Margin = System::Windows::Forms::Padding(4);
			this->CraftPanel->Name = L"CraftPanel";
			this->CraftPanel->Size = System::Drawing::Size(393, 193);
			this->CraftPanel->TabIndex = 4;
			//
			// CraftSlot9
			//
			this->CraftSlot9->AutoSize = true;
			this->CraftSlot9->Location = System::Drawing::Point(263, 130);
			this->CraftSlot9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CraftSlot9->Name = L"CraftSlot9";
			this->CraftSlot9->Size = System::Drawing::Size(115, 55);
			this->CraftSlot9->TabIndex = 29;
			this->CraftSlot9->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->CraftSlot9->UseVisualStyleBackColor = true;
			//
			// CraftSlot8
			//
			this->CraftSlot8->AutoSize = true;
			this->CraftSlot8->Location = System::Drawing::Point(137, 130);
			this->CraftSlot8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CraftSlot8->Name = L"CraftSlot8";
			this->CraftSlot8->Size = System::Drawing::Size(115, 55);
			this->CraftSlot8->TabIndex = 28;
			this->CraftSlot8->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->CraftSlot8->UseVisualStyleBackColor = true;
			//
			// CraftSlot7
			//
			this->CraftSlot7->AutoSize = true;
			this->CraftSlot7->Location = System::Drawing::Point(12, 130);
			this->CraftSlot7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CraftSlot7->Name = L"CraftSlot7";
			this->CraftSlot7->Size = System::Drawing::Size(115, 55);
			this->CraftSlot7->TabIndex = 27;
			this->CraftSlot7->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->CraftSlot7->UseVisualStyleBackColor = true;
			//
			// CraftSlot6
			//
			this->CraftSlot6->AutoSize = true;
			this->CraftSlot6->Location = System::Drawing::Point(263, 73);
			this->CraftSlot6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CraftSlot6->Name = L"CraftSlot6";
			this->CraftSlot6->Size = System::Drawing::Size(115, 55);
			this->CraftSlot6->TabIndex = 26;
			this->CraftSlot6->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->CraftSlot6->UseVisualStyleBackColor = true;
			//
			// CraftSlot5
			//
			this->CraftSlot5->AutoSize = true;
			this->CraftSlot5->Location = System::Drawing::Point(137, 73);
			this->CraftSlot5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CraftSlot5->Name = L"CraftSlot5";
			this->CraftSlot5->Size = System::Drawing::Size(115, 55);
			this->CraftSlot5->TabIndex = 25;
			this->CraftSlot5->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->CraftSlot5->UseVisualStyleBackColor = true;
			//
			// CraftSlot4
			//
			this->CraftSlot4->AutoSize = true;
			this->CraftSlot4->Location = System::Drawing::Point(12, 73);
			this->CraftSlot4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CraftSlot4->Name = L"CraftSlot4";
			this->CraftSlot4->Size = System::Drawing::Size(115, 55);
			this->CraftSlot4->TabIndex = 24;
			this->CraftSlot4->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->CraftSlot4->UseVisualStyleBackColor = true;
			//
			// CraftSlot3
			//
			this->CraftSlot3->AutoSize = true;
			this->CraftSlot3->Location = System::Drawing::Point(263, 15);
			this->CraftSlot3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CraftSlot3->Name = L"CraftSlot3";
			this->CraftSlot3->Size = System::Drawing::Size(115, 55);
			this->CraftSlot3->TabIndex = 23;
			this->CraftSlot3->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->CraftSlot3->UseVisualStyleBackColor = true;
			//
			// CraftSlot2
			//
			this->CraftSlot2->AutoSize = true;
			this->CraftSlot2->Location = System::Drawing::Point(137, 15);
			this->CraftSlot2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CraftSlot2->Name = L"CraftSlot2";
			this->CraftSlot2->Size = System::Drawing::Size(115, 55);
			this->CraftSlot2->TabIndex = 22;
			this->CraftSlot2->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->CraftSlot2->UseVisualStyleBackColor = true;
			//
			// CraftSlot1
			//
			this->CraftSlot1->AutoSize = true;
			this->CraftSlot1->Location = System::Drawing::Point(12, 15);
			this->CraftSlot1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CraftSlot1->Name = L"CraftSlot1";
			this->CraftSlot1->Size = System::Drawing::Size(115, 55);
			this->CraftSlot1->TabIndex = 21;
			this->CraftSlot1->Text = L"Slot Name\nItem Name\nDurability/Qty";
			this->CraftSlot1->UseVisualStyleBackColor = true;
			//
			// panel2
			//
			this->panel2->Controls->Add(this->ExportButton);
			this->panel2->Controls->Add(this->UseTooltip);
			this->panel2->Controls->Add(this->UseButton);
			this->panel2->Controls->Add(this->UseLabel);
			this->panel2->Controls->Add(this->MoveTooltip);
			this->panel2->Controls->Add(this->MoveButton);
			this->panel2->Controls->Add(this->MoveLabel);
			this->panel2->Controls->Add(this->DiscardTooltip);
			this->panel2->Controls->Add(this->DiscardButton);
			this->panel2->Controls->Add(this->DiscardLabel);
			this->panel2->Controls->Add(this->CommandTooltip);
			this->panel2->Controls->Add(this->GiveLabel);
			this->panel2->Controls->Add(this->CraftButton);
			this->panel2->Controls->Add(this->GiveQty);
			this->panel2->Controls->Add(this->GiveInput);
			this->panel2->Controls->Add(this->GiveButton);
			this->panel2->Location = System::Drawing::Point(435, 30);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(727, 190);
			this->panel2->TabIndex = 5;
			//
			// ExportButton
			//
			this->ExportButton->Location = System::Drawing::Point(124, 12);
			this->ExportButton->Name = L"ExportButton";
			this->ExportButton->Size = System::Drawing::Size(107, 74);
			this->ExportButton->TabIndex = 15;
			this->ExportButton->Text = L"Export Inventory";
			this->ExportButton->UseVisualStyleBackColor = true;
			this->ExportButton->Click += gcnew System::EventHandler(this, &Form1::ExportButton_Click);
			//
			// UseTooltip
			//
			this->UseTooltip->AutoSize = true;
			this->UseTooltip->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UseTooltip->Location = System::Drawing::Point(469, 64);
			this->UseTooltip->Name = L"UseTooltip";
			this->UseTooltip->Size = System::Drawing::Size(109, 18);
			this->UseTooltip->TabIndex = 14;
			this->UseTooltip->Text = L"Select 1 InvSlot";
			//
			// UseButton
			//
			this->UseButton->Location = System::Drawing::Point(471, 85);
			this->UseButton->Name = L"UseButton";
			this->UseButton->Size = System::Drawing::Size(75, 23);
			this->UseButton->TabIndex = 13;
			this->UseButton->Text = L"Use";
			this->UseButton->UseVisualStyleBackColor = true;
			//
			// UseLabel
			//
			this->UseLabel->AutoSize = true;
			this->UseLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UseLabel->Location = System::Drawing::Point(468, 38);
			this->UseLabel->Name = L"UseLabel";
			this->UseLabel->Size = System::Drawing::Size(84, 20);
			this->UseLabel->TabIndex = 12;
			this->UseLabel->Text = L"Use Item";
			//
			// MoveTooltip
			//
			this->MoveTooltip->AutoSize = true;
			this->MoveTooltip->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MoveTooltip->Location = System::Drawing::Point(247, 137);
			this->MoveTooltip->Name = L"MoveTooltip";
			this->MoveTooltip->Size = System::Drawing::Size(199, 18);
			this->MoveTooltip->TabIndex = 11;
			this->MoveTooltip->Text = L"Select 2 Slots (From and To)";
			//
			// MoveButton
			//
			this->MoveButton->Location = System::Drawing::Point(249, 158);
			this->MoveButton->Name = L"MoveButton";
			this->MoveButton->Size = System::Drawing::Size(75, 23);
			this->MoveButton->TabIndex = 10;
			this->MoveButton->Text = L"Move";
			this->MoveButton->UseVisualStyleBackColor = true;
			//
			// MoveLabel
			//
			this->MoveLabel->AutoSize = true;
			this->MoveLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MoveLabel->Location = System::Drawing::Point(246, 111);
			this->MoveLabel->Name = L"MoveLabel";
			this->MoveLabel->Size = System::Drawing::Size(95, 20);
			this->MoveLabel->TabIndex = 9;
			this->MoveLabel->Text = L"Move Item";
			//
			// DiscardTooltip
			//
			this->DiscardTooltip->AutoSize = true;
			this->DiscardTooltip->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DiscardTooltip->Location = System::Drawing::Point(247, 64);
			this->DiscardTooltip->Name = L"DiscardTooltip";
			this->DiscardTooltip->Size = System::Drawing::Size(109, 18);
			this->DiscardTooltip->TabIndex = 8;
			this->DiscardTooltip->Text = L"Select 1 InvSlot";
			//
			// DiscardButton
			//
			this->DiscardButton->Location = System::Drawing::Point(249, 85);
			this->DiscardButton->Name = L"DiscardButton";
			this->DiscardButton->Size = System::Drawing::Size(75, 23);
			this->DiscardButton->TabIndex = 7;
			this->DiscardButton->Text = L"Discard";
			this->DiscardButton->UseVisualStyleBackColor = true;
			//
			// DiscardLabel
			//
			this->DiscardLabel->AutoSize = true;
			this->DiscardLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DiscardLabel->Location = System::Drawing::Point(246, 38);
			this->DiscardLabel->Name = L"DiscardLabel";
			this->DiscardLabel->Size = System::Drawing::Size(117, 20);
			this->DiscardLabel->TabIndex = 6;
			this->DiscardLabel->Text = L"DIscard Item";
			//
			// CommandTooltip
			//
			this->CommandTooltip->AutoSize = true;
			this->CommandTooltip->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CommandTooltip->Location = System::Drawing::Point(246, 12);
			this->CommandTooltip->Name = L"CommandTooltip";
			this->CommandTooltip->Size = System::Drawing::Size(467, 18);
			this->CommandTooltip->TabIndex = 5;
			this->CommandTooltip->Text = L"For this command, please select Item Slot(s) according the parameter";
			//
			// GiveLabel
			//
			this->GiveLabel->AutoSize = true;
			this->GiveLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GiveLabel->Location = System::Drawing::Point(13, 100);
			this->GiveLabel->Name = L"GiveLabel";
			this->GiveLabel->Size = System::Drawing::Size(89, 20);
			this->GiveLabel->TabIndex = 4;
			this->GiveLabel->Text = L"Give Item";
			//
			// CraftButton
			//
			this->CraftButton->Location = System::Drawing::Point(17, 12);
			this->CraftButton->Margin = System::Windows::Forms::Padding(4);
			this->CraftButton->Name = L"CraftButton";
			this->CraftButton->Size = System::Drawing::Size(100, 74);
			this->CraftButton->TabIndex = 3;
			this->CraftButton->Text = L"Craft";
			this->CraftButton->UseVisualStyleBackColor = true;
			//
			// GiveQty
			//
			this->GiveQty->Location = System::Drawing::Point(157, 124);
			this->GiveQty->Margin = System::Windows::Forms::Padding(4);
			this->GiveQty->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6400, 0, 0, 0 });
			this->GiveQty->Name = L"GiveQty";
			this->GiveQty->Size = System::Drawing::Size(60, 22);
			this->GiveQty->TabIndex = 2;
			//
			// GiveInput
			//
			this->GiveInput->Location = System::Drawing::Point(17, 124);
			this->GiveInput->Margin = System::Windows::Forms::Padding(4);
			this->GiveInput->Name = L"GiveInput";
			this->GiveInput->Size = System::Drawing::Size(132, 22);
			this->GiveInput->TabIndex = 1;
			//
			// GiveButton
			//
			this->GiveButton->Location = System::Drawing::Point(17, 154);
			this->GiveButton->Margin = System::Windows::Forms::Padding(4);
			this->GiveButton->Name = L"GiveButton";
			this->GiveButton->Size = System::Drawing::Size(100, 28);
			this->GiveButton->TabIndex = 0;
			this->GiveButton->Text = L"Give";
			this->GiveButton->UseVisualStyleBackColor = true;
			//
			// CraftingLabel
			//
			this->CraftingLabel->AutoSize = true;
			this->CraftingLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CraftingLabel->Location = System::Drawing::Point(19, 9);
			this->CraftingLabel->Name = L"CraftingLabel";
			this->CraftingLabel->Size = System::Drawing::Size(88, 25);
			this->CraftingLabel->TabIndex = 6;
			this->CraftingLabel->Text = L"Crafting";
			//
			// ExecuteButton
			//
			this->ExecuteButton->Location = System::Drawing::Point(1028, 552);
			this->ExecuteButton->Name = L"ExecuteButton";
			this->ExecuteButton->Size = System::Drawing::Size(132, 35);
			this->ExecuteButton->TabIndex = 7;
			this->ExecuteButton->Text = L"Execute";
			this->ExecuteButton->UseVisualStyleBackColor = true;
			//
			// SaveExport
			//
			this->SaveExport->Filter = L"Text files|*.txt";
			//
			// ExceptionProvider
			//
			this->ExceptionProvider->ContainerControl = this;
			//
			// Form1
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1188, 602);
			this->Controls->Add(this->ExecuteButton);
			this->Controls->Add(this->CraftingLabel);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->CraftPanel);
			this->Controls->Add(this->InputBox);
			this->Controls->Add(this->ConsoleBox);
			this->Controls->Add(this->InvPanel);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form1";
			this->Text = L"MineHati";
			this->InvPanel->ResumeLayout(false);
			this->InvPanel->PerformLayout();
			this->CraftPanel->ResumeLayout(false);
			this->CraftPanel->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GiveQty))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ExceptionProvider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		System::Collections::ArrayList a;
	private:
		System::Void ExportButton_Click(System::Object^ sender, System::EventArgs^ e) {
			for (int i = 0; i < a.Count; i++) {
				MessageBox::Show(static_cast<Button^>(a[i])->Name);
			}
		}
		System::Void Slot_Click(System::Object^ sender, System::EventArgs^ e) {
			if (static_cast<CheckBox^>(sender)->Checked) {
				this->a.Add(sender);
			}
			else {
				this->a.Remove(sender);
			}
		}
	};
}
