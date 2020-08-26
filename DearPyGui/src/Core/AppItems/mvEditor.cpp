#include "mvEditor.h"
#include "Core/mvTextEditor.h"

namespace Marvel {

	mvEditor::mvEditor(const std::string& parent, const std::string& name)
		: mvAppItem(parent, name)
	{
		m_editor = new mvTextEditor();

		m_editor->SetLanguageDefinition(mvTextEditor::LanguageDefinition::Python());
	}

	mvEditor::~mvEditor()
	{
		delete m_editor;
		m_editor = nullptr;
	}

	void mvEditor::setPyValue(PyObject* value)
	{
		m_value = mvPythonTranslator::ToString(value, m_name + " requires a string value.");
		m_editor->SetText(m_value);
	}

	[[nodiscard]] PyObject* mvEditor::getPyValue() const
	{
		return mvPythonTranslator::ToPyString(m_editor->GetText());
	}

	void mvEditor::draw()
	{
		m_editor->Render("TextEditor");
	}

}