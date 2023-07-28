using System;
using System.Collections;
using System.Collections.Generic;
using Unity.Netcode;
using UnityEngine;

public class PlayerAnimator : NetworkBehaviour
{

    private Animator animator;

    [SerializeField] private Player player;     // Reference to the Player

    private void Awake()
    {
        animator = GetComponent<Animator>();
    }

    private void Update()
    {
        if (!IsOwner)
        {
            return;
        }

        animator.SetBool("isWalking", player.IsWalking());
    }


}
