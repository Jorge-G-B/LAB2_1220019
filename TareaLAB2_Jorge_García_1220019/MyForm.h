#pragma once
#include "Pista.h"

namespace TareaLAB2JorgeGarcía1220019 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnPrep;
	protected:

	private: System::Windows::Forms::Button^  BtnEmpezar;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  rTBRegistro;


	private: System::Windows::Forms::Timer^  timerPaso;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnPrep = (gcnew System::Windows::Forms::Button());
			this->BtnEmpezar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->rTBRegistro = (gcnew System::Windows::Forms::RichTextBox());
			this->timerPaso = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// btnPrep
			// 
			this->btnPrep->Location = System::Drawing::Point(29, 87);
			this->btnPrep->Name = L"btnPrep";
			this->btnPrep->Size = System::Drawing::Size(93, 31);
			this->btnPrep->TabIndex = 0;
			this->btnPrep->Text = L"Preparar Carrera";
			this->btnPrep->UseVisualStyleBackColor = true;
			this->btnPrep->Click += gcnew System::EventHandler(this, &MyForm::btnPrep_Click);
			// 
			// BtnEmpezar
			// 
			this->BtnEmpezar->Enabled = false;
			this->BtnEmpezar->Location = System::Drawing::Point(29, 124);
			this->BtnEmpezar->Name = L"BtnEmpezar";
			this->BtnEmpezar->Size = System::Drawing::Size(93, 23);
			this->BtnEmpezar->TabIndex = 2;
			this->BtnEmpezar->Text = L"Empezar Carrera";
			this->BtnEmpezar->UseVisualStyleBackColor = true;
			this->BtnEmpezar->Click += gcnew System::EventHandler(this, &MyForm::BtnEmpezar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(165, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Registro de Carrera: ";
			// 
			// rTBRegistro
			// 
			this->rTBRegistro->Location = System::Drawing::Point(128, 37);
			this->rTBRegistro->Name = L"rTBRegistro";
			this->rTBRegistro->Size = System::Drawing::Size(183, 251);
			this->rTBRegistro->TabIndex = 4;
			this->rTBRegistro->Text = L"";
			// 
			// timerPaso
			// 
			this->timerPaso->Interval = 1000;
			this->timerPaso->Tick += gcnew System::EventHandler(this, &MyForm::timerPaso_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(445, 316);
			this->Controls->Add(this->rTBRegistro);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->BtnEmpezar);
			this->Controls->Add(this->btnPrep);
			this->Name = L"MyForm";
			this->Text = L"Preparar Carrera";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: Pista *carrera = new Pista();

	private: System::Void btnPrep_Click(System::Object^  sender, System::EventArgs^  e) {
		carrera->Preparar();
		BtnEmpezar->Enabled = true;
	}
private: System::Void BtnEmpezar_Click(System::Object^  sender, System::EventArgs^  e) {
	rTBRegistro->Text = "¡BANG! + \n ¡Y ARRANCAN!";
	timerPaso->Enabled = true;

}
private: System::Void timerPaso_Tick(System::Object^  sender, System::EventArgs^  e) {
	
	Random^ rng = gcnew Random();
	if (carrera->PosLiebre() >= 70) {
		rTBRegistro->Text = rTBRegistro->Text + "\n  ¡GANA La Liebre!";
		timerPaso->Enabled = false;
	}
	else if (carrera->PosTortuga() >= 70) {
		rTBRegistro->Text = rTBRegistro->Text + "\n  ¡GANA La Tortuga!";
		timerPaso->Enabled = false;
	}
	else {
		carrera->PasoLiebre(rng->Next(1, 10));
		carrera->PasoTortuga(rng->Next(1, 10));
		if (carrera->PosLiebre() != carrera->PosTortuga()) {
			rTBRegistro->Text = rTBRegistro->Text + "\n --------------------------------------------";
			rTBRegistro->Text = rTBRegistro->Text + "\n  L=" + (System::Convert::ToString(carrera->PosLiebre())) + " T=" + (System::Convert::ToString(carrera->PosTortuga()));
		}
		else {
			rTBRegistro->Text = rTBRegistro->Text + "\n --------------------------------------------";
			rTBRegistro->Text = rTBRegistro->Text + "\n  OUCH!";
		}
	}
}
};
}
