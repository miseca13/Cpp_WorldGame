#pragma once
#include <iostream>
#include "Juego.h"
#include "Primero.h"

namespace JUEGOMUNDO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(int nivel, int habit, int tiempo)
		{
			InitializeComponent();
			srand(time(NULL));

			fondo = gcnew Bitmap("img/FONDO" + nivel + ".png");
			lid = gcnew Bitmap("img/LIDER" + nivel + ".png");
			ali = gcnew Bitmap("img/ALIADO" + nivel + ".png");
			age = gcnew Bitmap("img/AGENTE" + nivel + ".png");
			enf = gcnew Bitmap("img/HAB" + nivel + "ENF.png");
			sano = gcnew Bitmap("img/HAB" + nivel + "SANO.png");
			soundt = gcnew SoundPlayer("img/MEGALOVANIA.wav");

			this->Size = System::Drawing::Size(fondo->Width, fondo->Height);
			soundt->PlayLooping();
			juego = new Juego(habit, tiempo);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
		   Bitmap^ fondo;
		   Bitmap^ lid;
		   Bitmap^ ali;
		   Bitmap^ age;
		   Bitmap^ enf;
		   Bitmap^ sano;
		   SoundPlayer^ soundt;

		   Juego* juego;
#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 60;
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			   // 
			   // MyForm
			   // 
			   this->ClientSize = System::Drawing::Size(148, 100);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"MyForm";
			   this->Text = L"MyForm";
			   this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			   this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			   this->ResumeLayout(false);

		   }
#pragma endregion
		   Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			   Graphics^ g = this->CreateGraphics();
			   BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
			   BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);

			   if (juego->Ganar()){
				   soundt->Stop();
				   bf->Graphics->Clear(Color::Black);
				   Bitmap^ ganar = gcnew Bitmap("img/YOUWIN.png");
				   bf->Graphics->DrawImage(ganar, (this->Size.Width-ganar->Width)/2, (this->Size.Height-ganar->Height)/2);

			   }
			   
			   else if (juego->Perder()) {
				   soundt->Stop();
				   bf->Graphics->Clear(Color::Black);
				   Bitmap^ perder = gcnew Bitmap("img/GAMEOVER.png");
				   bf->Graphics->DrawImage(perder, (this->Size.Width - perder->Width) / 2, (this->Size.Height - perder->Height) / 2);
			   }

			   else {
				   bf->Graphics->DrawImage(fondo, 0, 0, fondo->Width, fondo->Height);
				   juego->Mostrar(bf->Graphics, lid, ali, age, sano, enf);
			   }

			   bf->Render(g);
		   }

		
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Down) { 
			juego->MoverLider(Abajo,this->Size.Width,this->Size.Height);
		}
		
		else if (e->KeyCode == Keys::Left) {
			juego->MoverLider(Izquierda, this->Size.Width,this->Size.Height);
		}
		
		else if (e->KeyCode == Keys::Right) { 
			juego->MoverLider(Derecha, this->Size.Width,this->Size.Height);
		}

		else if (e->KeyCode == Keys::Up) {
			juego->MoverLider(Arriba, this->Size.Width,this->Size.Height);
		}
		
		else if (e->KeyCode == Keys::A) {
			juego->LanzarAliado(fondo->Width);
		}
	}

	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->MoverLider(Ninguno, fondo->Width, fondo->Height);
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	soundt->Stop();
}
};
}
