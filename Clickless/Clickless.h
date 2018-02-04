#pragma once
#include <Windows.h>


// License: BSD 3-Clause License

//--------------------------------------------------------
void LeftClick() {
  //--------------------------------------------------------
  INPUT Input = { 0 };
  // left down 
  Input.type = INPUT_MOUSE;
  Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
  ::SendInput(1, &Input, sizeof(INPUT));

  // left up
  ::ZeroMemory(&Input, sizeof(INPUT));
  Input.type = INPUT_MOUSE;
  Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
  ::SendInput(1, &Input, sizeof(INPUT));
}

namespace Clickless {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;
  using namespace System::Security::Permissions;

  /// <summary>
  /// Summary for MyForm
  /// </summary>
  public ref class MyForm : public System::Windows::Forms::Form
  {
  public:
    MyForm(void)
    {
      InitializeComponent();

      m_sleep = 2000;
      m_paused_time = 0;
      m_active = false;
      m_clicked = false;
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


  private: System::Windows::Forms::TextBox^  txt_sleep;
  private: System::Windows::Forms::Button^  bttn_ok;
  private: System::Windows::Forms::Label^  label_delay;
  private: System::Windows::Forms::Label^  label_status;
  private: System::Windows::Forms::Label^  label_set_delay;
  private: Boolean m_active;
  private: Boolean m_clicked;
  private: UInt64 m_sleep;
  private: UInt64 m_paused_time;
  private: System::Windows::Forms::Timer^  tmr_timer0;
  private: System::Drawing::Point^ point_curr;
  private: System::Drawing::Point^ point_prev;
  private: System::Windows::Forms::Label^  label_debug;
  private: System::Windows::Forms::MenuStrip^  menuStrip1;
  private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
  private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;


  private: System::ComponentModel::IContainer^  components;
  protected:

  protected:

  private:

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
      this->txt_sleep = (gcnew System::Windows::Forms::TextBox());
      this->bttn_ok = (gcnew System::Windows::Forms::Button());
      this->label_delay = (gcnew System::Windows::Forms::Label());
      this->label_status = (gcnew System::Windows::Forms::Label());
      this->label_set_delay = (gcnew System::Windows::Forms::Label());
      this->tmr_timer0 = (gcnew System::Windows::Forms::Timer(this->components));
      this->label_debug = (gcnew System::Windows::Forms::Label());
      this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
      this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->point_prev = (gcnew System::Drawing::Point(0, 0));
      this->point_curr = (gcnew System::Drawing::Point(0, 0));
      this->menuStrip1->SuspendLayout();
      this->SuspendLayout();
      // 
      // txt_sleep
      // 
      this->txt_sleep->Location = System::Drawing::Point(152, 29);
      this->txt_sleep->Name = L"txt_sleep";
      this->txt_sleep->Size = System::Drawing::Size(48, 20);
      this->txt_sleep->TabIndex = 0;
      this->txt_sleep->Text = L"1000";
      this->txt_sleep->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
      // 
      // bttn_ok
      // 
      this->bttn_ok->Location = System::Drawing::Point(210, 97);
      this->bttn_ok->Name = L"bttn_ok";
      this->bttn_ok->Size = System::Drawing::Size(75, 23);
      this->bttn_ok->TabIndex = 1;
      this->bttn_ok->Text = L"OK";
      this->bttn_ok->UseVisualStyleBackColor = true;
      this->bttn_ok->Click += gcnew System::EventHandler(this, &MyForm::bttn_ok_Click);
      // 
      // label_delay
      // 
      this->label_delay->AutoSize = true;
      this->label_delay->Location = System::Drawing::Point(17, 52);
      this->label_delay->Name = L"label_delay";
      this->label_delay->Size = System::Drawing::Size(80, 13);
      this->label_delay->TabIndex = 2;
      this->label_delay->Text = L"Delay: 1000 ms";
      // 
      // label_status
      // 
      this->label_status->AutoSize = true;
      this->label_status->Location = System::Drawing::Point(17, 75);
      this->label_status->Name = L"label_status";
      this->label_status->Size = System::Drawing::Size(0, 13);
      this->label_status->TabIndex = 3;
      // 
      // label_set_delay
      // 
      this->label_set_delay->AutoSize = true;
      this->label_set_delay->Location = System::Drawing::Point(17, 29);
      this->label_set_delay->Name = L"label_set_delay";
      this->label_set_delay->Size = System::Drawing::Size(134, 13);
      this->label_set_delay->TabIndex = 4;
      this->label_set_delay->Text = L"Click delay (in milliseconds)";
      // 
      // tmr_timer0
      // 
      this->tmr_timer0->Interval = 500;
      this->tmr_timer0->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
      // 
      // label_debug
      // 
      this->label_debug->AutoSize = true;
      this->label_debug->Location = System::Drawing::Point(17, 98);
      this->label_debug->Name = L"label_debug";
      this->label_debug->Size = System::Drawing::Size(42, 13);
      this->label_debug->TabIndex = 5;
      this->label_debug->Text = L"Debug:";
      // 
      // menuStrip1
      // 
      this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem1 });
      this->menuStrip1->Location = System::Drawing::Point(0, 0);
      this->menuStrip1->Name = L"menuStrip1";
      this->menuStrip1->Size = System::Drawing::Size(297, 24);
      this->menuStrip1->TabIndex = 5;
      this->menuStrip1->Text = L"menuStrip1";
      // 
      // toolStripMenuItem1
      // 
      this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
      this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
      this->toolStripMenuItem1->Size = System::Drawing::Size(44, 20);
      this->toolStripMenuItem1->Text = L"Help";
      // 
      // aboutToolStripMenuItem
      // 
      this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
      this->aboutToolStripMenuItem->Size = System::Drawing::Size(152, 22);
      this->aboutToolStripMenuItem->Text = L"About";
      this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
      // 
      // MyForm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(297, 125);
      this->Controls->Add(this->label_set_delay);
      this->Controls->Add(this->label_status);
      this->Controls->Add(this->label_delay);
      this->Controls->Add(this->bttn_ok);
      this->Controls->Add(this->txt_sleep);
      this->Controls->Add(this->menuStrip1);
      this->MainMenuStrip = this->menuStrip1;
      this->Name = L"MyForm";
      this->Text = L"clickless by park";
      this->menuStrip1->ResumeLayout(false);
      this->menuStrip1->PerformLayout();
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: System::Void bttn_ok_Click(System::Object^  sender, System::EventArgs^  e) {
    try {
      m_sleep = Convert::ToUInt64(txt_sleep->Text);
    }
    catch (System::FormatException^ e) {
      UNREFERENCED_PARAMETER(e);
      if (!m_active) {
        update_Status(L"Error: enter an integer greater than 0");
        return;
      }
    }
    catch (System::OverflowException^ e) {
      UNREFERENCED_PARAMETER(e);
      m_sleep = UInt64::MaxValue;
    }

    if (!m_active) {
      bttn_ok->Text = L"Active";
      label_delay->Text = L"Delay " + txt_sleep->Text + " ms";
      update_Status(L"Active");
      tmr_timer0->Start();
    }
    else {
      bttn_ok->Text = L"OK";
      update_Status(L"Inactive");
      tmr_timer0->Stop();
    }

    m_active = !m_active;
  }

  private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
    point_curr = Control::MousePosition;

    // if there is no mouse movement, accumulate m_paused_time with the timer interval val
    if (point_curr->X == point_prev->X && point_curr->Y == point_prev->Y) {
      m_paused_time += tmr_timer0->Interval;
    }
    // otherwise reset
    else {
      m_clicked = false;
      m_paused_time = 0;
    }

    // copy curr to prev
    point_prev->X = point_curr->X;
    point_prev->Y = point_curr->Y;

    //label_debug->Text = L"Debug:" + Convert::ToString(m_paused_time) + L" ms paused, " + Convert::ToString(tmr_timer0->Interval) + L" ms interval, clicked=" + Convert::ToString(m_clicked);

    // if we've been idle for sleep threshold, and we haven't already clicked, then click
    if (m_paused_time >= m_sleep && !m_clicked) {
      // click
      LeftClick();
      m_clicked = true;
    }

  }

  private: System::Void update_Status(System::String^ msg) {
    label_status->Text = "Status: " + msg;
  }

  private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
    String^ l_caption = "About";
    String^ l_msg = "Copyright 2018 Phil Park (philparkbot)\nLicense: BSD 3-Clause License\nTwitter: @philparkbot";
    System::Windows::Forms::MessageBoxButtons l_buttons = System::Windows::Forms::MessageBoxButtons::OK;
    System::Windows::Forms::DialogResult l_result;

    l_result = MessageBox::Show(this, l_msg, l_caption, l_buttons);
  }
  };
} // namespace
