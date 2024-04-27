#pragma once
#include "MyForm.h"
#include "Opciones.h"

namespace JUEGOMUNDO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Primero
	/// </summary>
	public ref class Primero : public System::Windows::Forms::Form
	{
	public:
		Primero(void)
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
		~Primero()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ INSTRUCCIONES;
	private: System::Windows::Forms::PictureBox^ JUGAR;
	private: System::Windows::Forms::PictureBox^ REGLAS;
	private: System::Windows::Forms::PictureBox^ CREDITOS;
	protected:



	private: System::Windows::Forms::PictureBox^ PORTADA;




	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
			
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Primero::typeid));
			this->INSTRUCCIONES = (gcnew System::Windows::Forms::PictureBox());
			this->JUGAR = (gcnew System::Windows::Forms::PictureBox());
			this->REGLAS = (gcnew System::Windows::Forms::PictureBox());
			this->CREDITOS = (gcnew System::Windows::Forms::PictureBox());
			this->PORTADA = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->INSTRUCCIONES))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->JUGAR))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->REGLAS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CREDITOS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PORTADA))->BeginInit();
			this->SuspendLayout();
			// 
			// INSTRUCCIONES
			// 
			this->INSTRUCCIONES->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->INSTRUCCIONES->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"INSTRUCCIONES.Image")));
			this->INSTRUCCIONES->Location = System::Drawing::Point(0, 0);
			this->INSTRUCCIONES->Margin = System::Windows::Forms::Padding(2);
			this->INSTRUCCIONES->Name = L"INSTRUCCIONES";
			this->INSTRUCCIONES->Size = System::Drawing::Size(731, 442);
			this->INSTRUCCIONES->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->INSTRUCCIONES->TabIndex = 0;
			this->INSTRUCCIONES->TabStop = false;
			// 
			// JUGAR
			// 
			this->JUGAR->BackColor = System::Drawing::Color::Transparent;
			this->JUGAR->Cursor = System::Windows::Forms::Cursors::Hand;
			this->JUGAR->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"JUGAR.Image")));
			this->JUGAR->Location = System::Drawing::Point(84, 236);
			this->JUGAR->Margin = System::Windows::Forms::Padding(2);
			this->JUGAR->Name = L"JUGAR";
			this->JUGAR->Size = System::Drawing::Size(194, 61);
			this->JUGAR->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->JUGAR->TabIndex = 1;
			this->JUGAR->TabStop = false;
			this->JUGAR->Click += gcnew System::EventHandler(this, &Primero::JUGAR_Click);
			// 
			// REGLAS
			// 
			this->REGLAS->BackColor = System::Drawing::Color::Transparent;
			this->REGLAS->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->REGLAS->Cursor = System::Windows::Forms::Cursors::Hand;
			this->REGLAS->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"REGLAS.Image")));
			this->REGLAS->Location = System::Drawing::Point(423, 236);
			this->REGLAS->Margin = System::Windows::Forms::Padding(2);
			this->REGLAS->Name = L"REGLAS";
			this->REGLAS->Size = System::Drawing::Size(194, 61);
			this->REGLAS->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->REGLAS->TabIndex = 2;
			this->REGLAS->TabStop = false;
			this->REGLAS->Click += gcnew System::EventHandler(this, &Primero::pictureBox3_Click);
			// 
			// CREDITOS
			// 
			this->CREDITOS->Cursor = System::Windows::Forms::Cursors::Hand;
			this->CREDITOS->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CREDITOS.Image")));
			this->CREDITOS->Location = System::Drawing::Point(222, 346);
			this->CREDITOS->Margin = System::Windows::Forms::Padding(2);
			this->CREDITOS->Name = L"CREDITOS";
			this->CREDITOS->Size = System::Drawing::Size(261, 54);
			this->CREDITOS->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->CREDITOS->TabIndex = 3;
			this->CREDITOS->TabStop = false;
			this->CREDITOS->Click += gcnew System::EventHandler(this, &Primero::pictureBox1_Click);
			// 
			// PORTADA
			// 
			this->PORTADA->BackColor = System::Drawing::Color::Black;
			this->PORTADA->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PORTADA.Image")));
			this->PORTADA->Location = System::Drawing::Point(109, 83);
			this->PORTADA->Margin = System::Windows::Forms::Padding(2);
			this->PORTADA->Name = L"PORTADA";
			this->PORTADA->Size = System::Drawing::Size(484, 41);
			this->PORTADA->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->PORTADA->TabIndex = 4;
			this->PORTADA->TabStop = false;
			this->PORTADA->Click += gcnew System::EventHandler(this, &Primero::pictureBox2_Click);
			// 
			// Primero
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(723, 438);
			this->Controls->Add(this->PORTADA);
			this->Controls->Add(this->CREDITOS);
			this->Controls->Add(this->REGLAS);
			this->Controls->Add(this->JUGAR);
			this->Controls->Add(this->INSTRUCCIONES);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Primero";
			this->Text = L"MENU PRINCIPAL";
			this->Load += gcnew System::EventHandler(this, &Primero::Primero_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->INSTRUCCIONES))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->JUGAR))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->REGLAS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CREDITOS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PORTADA))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void JUGAR_Click(System::Object^ sender, System::EventArgs^ e) {
		Opciones^ opciones = gcnew Opciones();
		opciones->ShowDialog();

		int tiempo = opciones->getTiempo();
		int habs = opciones->getHabs();
		int nivel = opciones->getNivel();
		
		MyForm^ juego = gcnew MyForm(nivel,tiempo,habs);


		this->Visible = false;
		juego->ShowDialog();
		this->Visible = true;

		delete juego;
	}
	private: System::Void Primero_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Moverse con las flechas de direccion\nPresionar A para liberar a un aliado\n"+
			"Aliados demoran 3 segundos en salir y 2 en sanar a los habitantes\nCuando sale un aliado un agente lo persigue\n"+
			"Liberar aliados hasta sanar a todos los habitantes\nS U E R T E");
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Juegazo desarrollado por: \nKyara Abrigo \nDiego Lucana \nAngie Solorzano");
	}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
