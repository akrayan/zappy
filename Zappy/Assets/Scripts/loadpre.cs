using UnityEngine;
using UnityEngine.SceneManagement;

public class loadpre : MonoBehaviour
{
	public void LoadScene()
	{
		DontDestroyOnLoad(transform.gameObject);
		SceneManager.LoadScene("load");
	}
}