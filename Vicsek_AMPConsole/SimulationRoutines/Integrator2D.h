#pragma once
#include <string>
#include <vector>
#include "CommonStructs.h"

class CIntegrator2D
{
public:
	CIntegrator2D(TaskData2D& td, float_2 domain) {
		m_Task = &td;
		m_DomainSize = domain;
		Steps = 0;
	};

	~CIntegrator2D() {};

	std::vector<float> GetAverDensityDistributionY(int sliceCount);
	std::vector<float_2> GetAverVelocityDistributionY(int sliceCount);
	float_2 GetAverageVelocity();

	static float s_Noise;
	virtual void Init(TaskData2D& td, float_2 domain)
	{
		m_Task = &td;
		m_DomainSize = domain;
	};

	void IntegrateFor(int steps, float noise);
	void IntegrateWithAveragingFor(int steps, float noise, int sliceCount);

	std::vector<float> AverVelocityModuleDistribution;
	std::vector<float> AverDensityDistribution;

	int PtCount();
	void ResetSteps();
	int Steps;
protected:
	TaskData2D* m_Task;

	virtual bool RealIntegrate(float noise)
	{
		return false;
	};

	float_2 m_DomainSize;
	int m_IntR = 1;
	static const int s_TileSize = 512;
};