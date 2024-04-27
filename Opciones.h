#pragma once

namespace JUEGOMUNDO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Opciones
	/// </summary>
	public ref class Opciones : public System::Windows::Forms::Form
	{
	public:
		Opciones()
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Opciones()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ BOSQUE;
	public: System::Windows::Forms::PictureBox^ HOSPITAL;
	public: System::Windows::Forms::Label^ TIEMPO;
	public: System::Windows::Forms::Label^ Habitantes;
	public: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ getTIEMPO;
	private: System::Windows::Forms::TextBox^ getHABS;




	public:
		int nivel = 0;
	protected:

	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Opciones::typeid));
			this->BOSQUE = (gcnew System::Windows::Forms::PictureBox());
			this->HOSPITAL = (gcnew System::Windows::Forms::PictureBox());
			this->TIEMPO = (gcnew System::Windows::Forms::Label());
			this->Habitantes = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->getTIEMPO = (gcnew System::Windows::Forms::TextBox());
			this->getHABS = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BOSQUE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HOSPITAL))->BeginInit();
			this->SuspendLayout();
			// 
			// BOSQUE
			// 
			this->BOSQUE->BackColor = System::Drawing::Color::White;
			this->BOSQUE->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BOSQUE->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BOSQUE.Image")));
			this->BOSQUE->Location = System::Drawing::Point(30, 144);
			this->BOSQUE->Name = L"BOSQUE";
			this->BOSQUE->Size = System::Drawing::Size(153, 113);
			this->BOSQUE->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->BOSQUE->TabIndex = 0;
			this->BOSQUE->TabStop = false;
			this->BOSQUE->Click += gcnew System::EventHandler(this, &Opciones::BOSQUE_Click);
			// 
			// HOSPITAL
			// 
			this->HOSPITAL->BackColor = System::Drawing::Color::White;
			this->HOSPITAL->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HOSPITAL->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"HOSPITAL.Image")));
			this->HOSPITAL->Location = System::Drawing::Point(218, 144);
			this->HOSPITAL->Name = L"HOSPITAL";
			this->HOSPITAL->Size = System::Drawing::Size(153, 113);
			this->HOSPITAL->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->HOSPITAL->TabIndex = 1;
			this->HOSPITAL->TabStop = false;
			this->HOSPITAL->Click += gcnew System::EventHandler(this, &Opciones::HOSPITAL_Click);
			// 
			// TIEMPO
			// 
			this->TIEMPO->AutoSize = true;
			this->TIEMPO->Location = System::Drawing::Point(101, 33);
			this->TIEMPO->Name = L"TIEMPO";
			this->TIEMPO->Size = System::Drawing::Size(45, 13);
			this->TIEMPO->TabIndex = 2;
			this->TIEMPO->Text = L"Tiempo:";
			// 
			// Habitantes
			// 
			this->Habitantes->AutoSize = true;
			this->Habitantes->Location = System::Drawing::Point(101, 70);
			this->Habitantes->Name = L"Habitantes";
			this->Habitantes->Size = System::Drawing::Size(61, 13);
			this->Habitantes->TabIndex = 3;
			this->Habitantes->Text = L"Habitantes:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(101, 105);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nivel:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(159, 288);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"JUGAR!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Opciones::button1_Click);
			// 
			// getTIEMPO
			// 
			this->getTIEMPO->Location = System::Drawing::Point(218, 26);
			this->getTIEMPO->Name = L"getTIEMPO";
			this->getTIEMPO->Size = System::Drawing::Size(100, 20);
			this->getTIEMPO->TabIndex = 6;
			// 
			// getHABS
			// 
			this->getHABS->Location = System::Drawing::Point(218, 63);
			this->getHABS->Name = L"getHABS";
			this->getHABS->Size = System::Drawing::Size(100, 20);
			this->getHABS->TabIndex = 7;
			// 
			// Opciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(408, 323);
			this->Controls->Add(this->getHABS);
			this->Controls->Add(this->getTIEMPO);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Habitantes);
			this->Controls->Add(this->TIEMPO);
			this->Controls->Add(this->HOSPITAL);
			this->Controls->Add(this->BOSQUE);
			this->Name = L"Opciones";
			this->Text = L"Opciones";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BOSQUE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HOSPITAL))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
public:
	int getNivel() {
		return nivel;
	}

	int getHabs() {
		return Convert::ToInt32(getHABS->Text);
	}

	int getTiempo() {
		return Convert::ToInt32(getTIEMPO->Text);
	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (getTIEMPO->Text != "" && getHABS->Text != "" && nivel != 0) {
		this->Close();
	}

	else {
		MessageBox::Show("INGRESAR TODOS LOS DATOS!");
	}
}
private: System::Void BOSQUE_Click(System::Object^ sender, System::EventArgs^ e) {
	BOSQUE->BackColor = Color::Blue;
	HOSPITAL->BackColor = Color::White;
	nivel = 1;
}
private: System::Void HOSPITAL_Click(System::Object^ sender, System::EventArgs^ e) {
	BOSQUE->BackColor = Color::White;
	HOSPITAL->BackColor = Color::Blue;
	nivel = 2;
}
};
}
