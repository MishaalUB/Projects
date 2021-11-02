@extends('layouts.app')

@section('content')
<div class="container">
    @foreach($posts as $post)
        <div class="row">
            <div class="col-7 offset-3">
                <a href="/profile/{{ $post->user->id }}">
                    <img src="/storage/{{ $post->image }}" class="w-75">
                </a>
            </div>
        </div>
        <div class="row pt-3"></div>
            <div class="col-7 offset-3">
                <div>
                    <p>
                    <span class="font-weight-bold">
                        <a href="/profile/{{ $post->user->id }}">
                            <span class="text-dark" style="font-size: medium">{{ $post->user->username }}</span>
                        </a>
                    </span>
                        <span class="pl-2">{{ $post->caption }}</span>
                    </p>
                </div>
            </div>
    @endforeach

        <div class="row">
            <div class="col-12 d-flex justify-content-center">
                {{ $posts->links('pagination::bootstrap-4') }}
            </div>
        </div>
</div>
@endsection
