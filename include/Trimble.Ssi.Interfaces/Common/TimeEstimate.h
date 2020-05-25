#ifndef TIMEESTIMATE_H_
#define TIMEESTIMATE_H_
namespace  SSI
{
	class TimeEstimate
	{
	public:

		TimeEstimate();
		TimeEstimate(unsigned timeElapsed, unsigned timeRemaining, unsigned predictedDuration);
		TimeEstimate(unsigned predictedDuration);
		virtual ~TimeEstimate();

		/**
		* Elapsed time since the start of a task
		* @return
		* The time elapsed.
		*/
		unsigned getTimeElapsed();


		/**
		* Estimated time remaining until a task is completed
		* @return
		* The time remaining.
		*/
		unsigned getTimeRemaining();


		/**
		* Estimation of the total time duration of a task
		* @return
		* The duration of the predicted.
		*/
		unsigned getPredictedDuration();

	private:
		unsigned _timeElapsed;
		unsigned _timeRemaining;
		unsigned _predictedDuration;
	};
}

#endif