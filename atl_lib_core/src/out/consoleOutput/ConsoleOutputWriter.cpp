#include "../../template.h"
#include "ConsoleOutputWriter.h"
#include "ConsoleResultStringWriter.h"

void ConsoleOutputWriter::write(const TestData& allTests){
	ConsoleResultStringWriter stringWriter;

	m_presenter.addResultToStringWriter(AllTestView(allTests), stringWriter);

	std::cout<< stringWriter.getStringResult();
}
