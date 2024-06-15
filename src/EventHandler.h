
namespace Game {

	class EventHandler {
	public:
		EventHandler();
		void setupCallbacks();

	private:
		void framebufferResizeCallback();
		void key_callback();
		void collision_callback(); //idk just invented this one
	};

}
