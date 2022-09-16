#include "BreakOut.h"
#include <iostream>
#include"GameController.h"
#include "App.h"

void BreakOut::Init(GameController& controller)
{
	controller.ClearAll();
	ResetGame();

	ButtonAction leftKeyAction;
	leftKeyAction.key = GameController::LeftKey();
	leftKeyAction.action = [this](uint32_t dt, InputState state) {
		if (GameController::IsPressed(state))
		{
			mPaddle.SetMovementDirection(PaddleDirection::LEFT);
		}
		else
		{
			mPaddle.UnsetMovementDirection(PaddleDirection::LEFT);
		}
	};
	controller.AddInputActionForKey(leftKeyAction);

	ButtonAction rightKeyAction;
	rightKeyAction.key = GameController::RightKey();
	rightKeyAction.action = [this](uint32_t dt, InputState state) {
		if (GameController::IsPressed(state))
		{
			mPaddle.SetMovementDirection(PaddleDirection::RIGHT);
		}
		else
		{
			mPaddle.UnsetMovementDirection(PaddleDirection::RIGHT);
		}
	};

	controller.AddInputActionForKey(rightKeyAction);
}

void BreakOut::Update(uint32_t dt)
{
	mPaddle.Update(dt);
}

void BreakOut::Draw(Screen& screen)
{
	mPaddle.Draw(screen);
}

std::string BreakOut::GetName() const
{
	return "BreakOut";
}

void BreakOut::ResetGame()
{
	Vec2D PaddlePos(App::Singleton().Width() / 2 - Paddle::PADDLE_WIDTH / 2,
		App::Singleton().Height() - 8 * Paddle::PADDLE_HEIGHT);
	AARectangle paddleRect(PaddlePos, Paddle::PADDLE_WIDTH, Paddle::PADDLE_HEIGHT);

	AARectangle levelBoundary = { Vec2D::ZERO, App::Singleton().Width(), App::Singleton().Height() };
	mPaddle.Init(paddleRect, levelBoundary);
}
