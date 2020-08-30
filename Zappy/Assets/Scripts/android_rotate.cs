using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class android_rotate : MonoBehaviour {

    public GameObject camera;
    public float speed;
    bool left;
    bool up;
    bool down;
    bool right;

    public void move_right()
    {
        if (right == true)
        {
            GetComponent<Camera>().transform.Rotate(new Vector3(0, 1 * Time.deltaTime * speed, 0));
        }
    }

    public void none_right()
    {
        right = false;
    }

    public void right_right()
    {
        right = true;
    }

    public void move_left()
    {
        if (left == true)
        {
            GetComponent<Camera>().transform.Rotate(new Vector3(0, -1 * Time.deltaTime * speed, 0));
        }
    }

    public void none_left()
    {
        left = false;
    }

    public void right_left()
    {
        left = true;
    }

    public void move_down()
    {
        if (down == true)
        {
            GetComponent<Camera>().transform.Rotate(new Vector3(1 * Time.deltaTime * speed, 0, 0));
        }
    }

    public void none_down()
    {
        down = false;
    }

    public void right_down()
    {
        down = true;
    }

    public void move_up()
    {
        if (up == true)
        {
            GetComponent<Camera>().transform.Rotate(new Vector3(-1 * Time.deltaTime * speed, 0, 0));
        }
    }

    public void none_up()
    {
        up = false;
    }

    public void right_up()
    {
        up = true;
    }

}
